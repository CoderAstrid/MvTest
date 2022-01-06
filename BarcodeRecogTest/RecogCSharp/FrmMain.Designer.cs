namespace RecogCSharp
{
    partial class FrmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.ListViewItem listViewItem6 = new System.Windows.Forms.ListViewItem(new string[] {
            "1",
            "1200ms",
            "2",
            "1231234123421",
            "testtesttest123.jpg"}, -1);
            this.lblPath = new System.Windows.Forms.Label();
            this.txtPath = new System.Windows.Forms.TextBox();
            this.btnBrowse = new System.Windows.Forms.Button();
            this.picWnd = new System.Windows.Forms.PictureBox();
            this.btnFirst = new System.Windows.Forms.Button();
            this.btnPrev = new System.Windows.Forms.Button();
            this.lblNumber = new System.Windows.Forms.Label();
            this.btnLast = new System.Windows.Forms.Button();
            this.btnNext = new System.Windows.Forms.Button();
            this.lstRes = new System.Windows.Forms.ListView();
            this.colNo = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colTm = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colCnt = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colRes = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colFile = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.openFileDlg = new System.Windows.Forms.OpenFileDialog();
            this.chkBar = new System.Windows.Forms.CheckBox();
            this.chkQR = new System.Windows.Forms.CheckBox();
            this.chkSame = new System.Windows.Forms.CheckBox();
            this.label1 = new System.Windows.Forms.Label();
            this.spinMinLen = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.txtCharset = new System.Windows.Forms.TextBox();
            this.btnProcess = new System.Windows.Forms.Button();
            this.btnSetPar = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.picWnd)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spinMinLen)).BeginInit();
            this.SuspendLayout();
            // 
            // lblPath
            // 
            this.lblPath.AutoSize = true;
            this.lblPath.Location = new System.Drawing.Point(14, 17);
            this.lblPath.Name = "lblPath";
            this.lblPath.Size = new System.Drawing.Size(64, 13);
            this.lblPath.TabIndex = 0;
            this.lblPath.Text = "Image Path:";
            // 
            // txtPath
            // 
            this.txtPath.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtPath.Location = new System.Drawing.Point(84, 13);
            this.txtPath.Name = "txtPath";
            this.txtPath.Size = new System.Drawing.Size(906, 20);
            this.txtPath.TabIndex = 1;
            // 
            // btnBrowse
            // 
            this.btnBrowse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnBrowse.Location = new System.Drawing.Point(996, 12);
            this.btnBrowse.Name = "btnBrowse";
            this.btnBrowse.Size = new System.Drawing.Size(36, 23);
            this.btnBrowse.TabIndex = 2;
            this.btnBrowse.Text = "...";
            this.btnBrowse.UseVisualStyleBackColor = true;
            this.btnBrowse.Click += new System.EventHandler(this.btnBrowse_Click);
            // 
            // picWnd
            // 
            this.picWnd.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.picWnd.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.picWnd.Location = new System.Drawing.Point(13, 46);
            this.picWnd.Name = "picWnd";
            this.picWnd.Size = new System.Drawing.Size(659, 446);
            this.picWnd.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picWnd.TabIndex = 3;
            this.picWnd.TabStop = false;
            this.picWnd.Paint += new System.Windows.Forms.PaintEventHandler(this.picWnd_Paint);
            this.picWnd.DoubleClick += new System.EventHandler(this.picWnd_DoubleClick);
            // 
            // btnFirst
            // 
            this.btnFirst.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnFirst.Location = new System.Drawing.Point(13, 499);
            this.btnFirst.Name = "btnFirst";
            this.btnFirst.Size = new System.Drawing.Size(44, 23);
            this.btnFirst.TabIndex = 4;
            this.btnFirst.Text = "<<";
            this.btnFirst.UseVisualStyleBackColor = true;
            this.btnFirst.Click += new System.EventHandler(this.btnFirst_Click);
            // 
            // btnPrev
            // 
            this.btnPrev.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnPrev.Location = new System.Drawing.Point(63, 499);
            this.btnPrev.Name = "btnPrev";
            this.btnPrev.Size = new System.Drawing.Size(44, 23);
            this.btnPrev.TabIndex = 5;
            this.btnPrev.Text = "<";
            this.btnPrev.UseVisualStyleBackColor = true;
            this.btnPrev.Click += new System.EventHandler(this.btnPrev_Click);
            // 
            // lblNumber
            // 
            this.lblNumber.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblNumber.Location = new System.Drawing.Point(113, 499);
            this.lblNumber.Name = "lblNumber";
            this.lblNumber.Size = new System.Drawing.Size(93, 23);
            this.lblNumber.TabIndex = 6;
            this.lblNumber.Text = "lblNumber";
            this.lblNumber.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnLast
            // 
            this.btnLast.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnLast.Location = new System.Drawing.Point(262, 499);
            this.btnLast.Name = "btnLast";
            this.btnLast.Size = new System.Drawing.Size(44, 23);
            this.btnLast.TabIndex = 8;
            this.btnLast.Text = ">>";
            this.btnLast.UseVisualStyleBackColor = true;
            this.btnLast.Click += new System.EventHandler(this.btnLast_Click);
            // 
            // btnNext
            // 
            this.btnNext.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnNext.Location = new System.Drawing.Point(212, 499);
            this.btnNext.Name = "btnNext";
            this.btnNext.Size = new System.Drawing.Size(44, 23);
            this.btnNext.TabIndex = 7;
            this.btnNext.Text = ">";
            this.btnNext.UseVisualStyleBackColor = true;
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            // 
            // lstRes
            // 
            this.lstRes.Alignment = System.Windows.Forms.ListViewAlignment.SnapToGrid;
            this.lstRes.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lstRes.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colNo,
            this.colTm,
            this.colCnt,
            this.colRes,
            this.colFile});
            this.lstRes.FullRowSelect = true;
            this.lstRes.GridLines = true;
            this.lstRes.HideSelection = false;
            this.lstRes.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem6});
            this.lstRes.Location = new System.Drawing.Point(678, 46);
            this.lstRes.Name = "lstRes";
            this.lstRes.Size = new System.Drawing.Size(354, 500);
            this.lstRes.TabIndex = 9;
            this.lstRes.UseCompatibleStateImageBehavior = false;
            this.lstRes.View = System.Windows.Forms.View.Details;
            // 
            // colNo
            // 
            this.colNo.Text = "No";
            this.colNo.Width = 40;
            // 
            // colTm
            // 
            this.colTm.Text = "Time";
            // 
            // colCnt
            // 
            this.colCnt.Text = "Count";
            this.colCnt.Width = 40;
            // 
            // colRes
            // 
            this.colRes.Text = "Result";
            this.colRes.Width = 120;
            // 
            // colFile
            // 
            this.colFile.Text = "Filename";
            this.colFile.Width = 400;
            // 
            // openFileDlg
            // 
            this.openFileDlg.FileName = "openFileDlg";
            this.openFileDlg.Filter = "Image files|*.bmp;*.jpg;*.png;*.gif|All files (*.*)|*.*";
            // 
            // chkBar
            // 
            this.chkBar.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.chkBar.AutoSize = true;
            this.chkBar.Checked = true;
            this.chkBar.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkBar.Location = new System.Drawing.Point(522, 503);
            this.chkBar.Name = "chkBar";
            this.chkBar.Size = new System.Drawing.Size(66, 17);
            this.chkBar.TabIndex = 10;
            this.chkBar.Text = "Barcode";
            this.chkBar.UseVisualStyleBackColor = true;
            // 
            // chkQR
            // 
            this.chkQR.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.chkQR.AutoSize = true;
            this.chkQR.Checked = true;
            this.chkQR.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkQR.Location = new System.Drawing.Point(594, 503);
            this.chkQR.Name = "chkQR";
            this.chkQR.Size = new System.Drawing.Size(66, 17);
            this.chkQR.TabIndex = 11;
            this.chkQR.Text = "QRcode";
            this.chkQR.UseVisualStyleBackColor = true;
            // 
            // chkSame
            // 
            this.chkSame.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.chkSame.AutoSize = true;
            this.chkSame.Location = new System.Drawing.Point(12, 530);
            this.chkSame.Name = "chkSame";
            this.chkSame.Size = new System.Drawing.Size(53, 17);
            this.chkSame.TabIndex = 12;
            this.chkSame.Text = "Same";
            this.chkSame.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(81, 532);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 13);
            this.label1.TabIndex = 13;
            this.label1.Text = "Min Length";
            // 
            // spinMinLen
            // 
            this.spinMinLen.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.spinMinLen.Location = new System.Drawing.Point(147, 528);
            this.spinMinLen.Maximum = new decimal(new int[] {
            64,
            0,
            0,
            0});
            this.spinMinLen.Minimum = new decimal(new int[] {
            4,
            0,
            0,
            0});
            this.spinMinLen.Name = "spinMinLen";
            this.spinMinLen.Size = new System.Drawing.Size(59, 20);
            this.spinMinLen.TabIndex = 14;
            this.spinMinLen.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(234, 532);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(46, 13);
            this.label2.TabIndex = 15;
            this.label2.Text = "Charset:";
            // 
            // txtCharset
            // 
            this.txtCharset.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtCharset.Location = new System.Drawing.Point(286, 528);
            this.txtCharset.Name = "txtCharset";
            this.txtCharset.Size = new System.Drawing.Size(305, 20);
            this.txtCharset.TabIndex = 16;
            this.txtCharset.Text = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            // 
            // btnProcess
            // 
            this.btnProcess.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btnProcess.Location = new System.Drawing.Point(325, 499);
            this.btnProcess.Name = "btnProcess";
            this.btnProcess.Size = new System.Drawing.Size(75, 23);
            this.btnProcess.TabIndex = 17;
            this.btnProcess.Text = "Process";
            this.btnProcess.UseVisualStyleBackColor = true;
            this.btnProcess.Click += new System.EventHandler(this.btnProcess_Click);
            // 
            // btnSetPar
            // 
            this.btnSetPar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.btnSetPar.Location = new System.Drawing.Point(597, 527);
            this.btnSetPar.Name = "btnSetPar";
            this.btnSetPar.Size = new System.Drawing.Size(75, 23);
            this.btnSetPar.TabIndex = 18;
            this.btnSetPar.Text = "Set";
            this.btnSetPar.UseVisualStyleBackColor = true;
            this.btnSetPar.Click += new System.EventHandler(this.btnSetPar_Click);
            // 
            // FrmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1039, 554);
            this.Controls.Add(this.btnSetPar);
            this.Controls.Add(this.btnProcess);
            this.Controls.Add(this.txtCharset);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.spinMinLen);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.chkSame);
            this.Controls.Add(this.chkQR);
            this.Controls.Add(this.chkBar);
            this.Controls.Add(this.lstRes);
            this.Controls.Add(this.btnLast);
            this.Controls.Add(this.btnNext);
            this.Controls.Add(this.lblNumber);
            this.Controls.Add(this.btnPrev);
            this.Controls.Add(this.btnFirst);
            this.Controls.Add(this.picWnd);
            this.Controls.Add(this.btnBrowse);
            this.Controls.Add(this.txtPath);
            this.Controls.Add(this.lblPath);
            this.Name = "FrmMain";
            this.Text = "Barcode Recognition Demo";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.FrmMain_FormClosed);
            this.Load += new System.EventHandler(this.FrmMain_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picWnd)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spinMinLen)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblPath;
        private System.Windows.Forms.TextBox txtPath;
        private System.Windows.Forms.Button btnBrowse;
        private System.Windows.Forms.PictureBox picWnd;
        private System.Windows.Forms.Button btnFirst;
        private System.Windows.Forms.Button btnPrev;
        private System.Windows.Forms.Label lblNumber;
        private System.Windows.Forms.Button btnLast;
        private System.Windows.Forms.Button btnNext;
        private System.Windows.Forms.ListView lstRes;
        private System.Windows.Forms.ColumnHeader colNo;
        private System.Windows.Forms.ColumnHeader colTm;
        private System.Windows.Forms.ColumnHeader colCnt;
        private System.Windows.Forms.ColumnHeader colRes;
        private System.Windows.Forms.ColumnHeader colFile;
        private System.Windows.Forms.OpenFileDialog openFileDlg;
        private System.Windows.Forms.CheckBox chkBar;
        private System.Windows.Forms.CheckBox chkQR;
        private System.Windows.Forms.CheckBox chkSame;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown spinMinLen;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtCharset;
        private System.Windows.Forms.Button btnProcess;
        private System.Windows.Forms.Button btnSetPar;
    }
}

