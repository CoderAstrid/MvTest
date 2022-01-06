using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.IO;

namespace RecogCSharp
{
    public partial class FrmMain : Form
    {
        public string folder_path;
        public List<string> image_files = new List<string>();
        int cur_file = -1;
        List<CodeRecogRes> recorg_result = new List<CodeRecogRes>();

        public static byte[] ImageToByte(Image img)
        {            
            using (var stream = new MemoryStream())
            {
                img.Save(stream, System.Drawing.Imaging.ImageFormat.Bmp);
                Bitmap bmp = new Bitmap(stream);
                ImageConverter converter = new ImageConverter();

                Rectangle rect = new Rectangle(0, 0, bmp.Width, bmp.Height);
                System.Drawing.Imaging.BitmapData bmpData =
                    bmp.LockBits(rect, System.Drawing.Imaging.ImageLockMode.ReadWrite,
                    bmp.PixelFormat);
                
                IntPtr ptr = bmpData.Scan0;
                int bytes = Math.Abs(bmpData.Stride) * bmp.Height;
                byte[] rgbValues = new byte[bytes];
                System.Runtime.InteropServices.Marshal.Copy(ptr, rgbValues, 0, bytes);
                bmp.UnlockBits(bmpData);
                return rgbValues;
            }
        }

        public FrmMain()
        {
            InitializeComponent();
        }

        private void FrmMain_Load(object sender, EventArgs e)
        {
            int res = RecogEngine2SDK.SvEngineInit();
            if(res < 0)
            {
                MessageBox.Show("SDK Failed");
            }
            lstRes.Items.Clear();
        }

        private void FrmMain_FormClosed(object sender, FormClosedEventArgs e)
        {
            int res = RecogEngine2SDK.SvEngineClose();
        }

        private void btnBrowse_Click(object sender, EventArgs e)
        {
            if(openFileDlg.ShowDialog() == DialogResult.OK)
            {
                string filename = openFileDlg.FileName;
                txtPath.Text = filename;
                int k = filename.LastIndexOf('\\');
                folder_path = filename.Substring(0, k+1);
                string[] bmpfiles = Directory.GetFiles(folder_path, "*.bmp");
                string[] jpgfiles = Directory.GetFiles(folder_path, "*.jpg");
                string[] pngfiles = Directory.GetFiles(folder_path, "*.png");
                string[] giffiles = Directory.GetFiles(folder_path, "*.gif");

                image_files.Clear();
                foreach(string a in bmpfiles)
                    image_files.Add(a);
                foreach (string a in jpgfiles)
                    image_files.Add(a);
                foreach (string a in pngfiles)
                    image_files.Add(a);
                foreach (string a in giffiles)
                    image_files.Add(a);
                image_files.Sort();
                cur_file = image_files.IndexOf(filename);

                update_controls();
            }
        }

        private void update_controls()
        {
            int codeType = 0;
            if (chkBar.Checked)
                codeType += 1;
            if (chkQR.Checked)
                codeType += 2;

            lblNumber.Text = (cur_file + 1).ToString() + "/" + image_files.Count.ToString();
            if (cur_file > 0)
            {
                btnFirst.Enabled = true;
                btnPrev.Enabled = true;
            }
            if (cur_file < image_files.Count-1)
            {
                btnLast.Enabled = true;
                btnNext.Enabled = true;
            }
            txtPath.Text = image_files[cur_file];
            Image img = Image.FromFile(image_files[cur_file]);
            picWnd.Image = img;
            
            int bpp = Image.GetPixelFormatSize(img.PixelFormat);
            bpp = 24;
            byte[] buf = ImageToByte(img);
            CodeRecogRes[] recogRes = null;

            recorg_result.Clear();

            var bmp = new Bitmap(img.Width, img.Height, System.Drawing.Imaging.PixelFormat.Format24bppRgb);
            using (var gr = Graphics.FromImage(bmp))
                gr.DrawImage(img, new Rectangle(0, 0, img.Width, img.Height));

            double tm = RecogEngine2SDK.GetPerfCounter();
            int iRes = RecogEngine2SDK.SvEngineRec(bmp, codeType, ref recogRes);
            tm = RecogEngine2SDK.GetPerfCounter() - tm;

            ListViewItem aLine = new ListViewItem();

            aLine.Text = (lstRes.Items.Count + 1).ToString();
            string timems = tm.ToString("f2");
            aLine.SubItems.Add(timems + " ms");
            aLine.SubItems.Add(iRes.ToString());
            aLine.SubItems.Add("");
            aLine.SubItems.Add(image_files[cur_file]);
            if (iRes > 0)
            {
                for(int i = 0; i < recogRes.Length; i++)
                {
                    recorg_result.Add(recogRes[i]);                    
                }
            }
            lstRes.Items.Add(aLine);
            picWnd.Invalidate();
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            int new_idx = cur_file + 1;
            if (new_idx < image_files.Count)
            {
                cur_file = new_idx;
                update_controls();
            }
        }

        private void btnLast_Click(object sender, EventArgs e)
        {
            if (image_files.Count > 0)
            {
                cur_file = image_files.Count - 1;
                update_controls();
            }
        }

        private void btnPrev_Click(object sender, EventArgs e)
        {
            int new_idx = cur_file - 1;
            if(new_idx >= 0)
            {
                cur_file = new_idx;
                update_controls();
            }
        }

        private void btnFirst_Click(object sender, EventArgs e)
        {
            if (image_files.Count > 0)
            {
                cur_file = 0;
                update_controls();
            }
        }

        private void picWnd_DoubleClick(object sender, EventArgs e)
        {
            picWnd.SizeMode = PictureBoxSizeMode.CenterImage;            
        }

        private void picWnd_Paint(object sender, PaintEventArgs e)
        {
            if (picWnd.Image != null)
            {
                int w = picWnd.Image.Width;
                int h = picWnd.Image.Height;
                int wp = picWnd.Width;
                int hp = picWnd.Height;
                Font myFont = new Font("Arial", 14);
                using (Pen pen = new Pen(Color.Red, 2))
                {
                    foreach(CodeRecogRes a in recorg_result)
                    {                        
                        for(int i = 0; i <  a.countRegion; i++)
                        {
                            PointF[] pts = new PointF[4];
                            for (int j = 0; j < 4; j++)
                            {
                                pts[j].X = a.corner_x[i * 4 + j] * wp / w;
                                pts[j].Y = a.corner_y[i * 4 + j] * hp / h;
                            }
                            e.Graphics.DrawPolygon(pen, pts);
                        }
                        string str_out = new string(a.sText);
                        int len = str_out.IndexOf('\0');
                        str_out = new String(a.sText, 0, len);

                        e.Graphics.DrawString(str_out, myFont, Brushes.Green, 
                            new Point(a.rcRoi.left * wp / w, a.rcRoi.top * hp / h)
                        );
                    }
                }
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            update_controls();
        }

        private void btnSetPar_Click(object sender, EventArgs e)
        {
            SvBarRecParams par = new SvBarRecParams();
            RecogEngine2SDK.SvEngineGetParam(ref par);
            par.isAllSame = chkSame.Checked;
            par.minStringLength = (int)spinMinLen.Value;
            RecogEngine2SDK.SvEngineSetParam(par);
        }
    }
}
//.EOF