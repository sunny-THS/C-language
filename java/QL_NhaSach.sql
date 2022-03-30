IF NOT EXISTS(SELECT * FROM sys.databases WHERE name='QL_NhaSach')
BEGIN
	CREATE DATABASE [QL_NhaSach]
END
GO
USE [QL_NhaSach]
GO
/****** Object:  Table [dbo].[ChiTietHoaDon]    Script Date: 15/07/2020 3:47:59 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ChiTietHoaDon](
	[CTHD_ID] [int] NOT NULL,
	[IDHoaDon] [int] NULL,
	[IDSach] [int] NULL,
	[SoLuong] [int] NULL,
	[GiaBan] [float] NULL,
 CONSTRAINT [PK_ChiTietHoaDon] PRIMARY KEY CLUSTERED
(
	[CTHD_ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ChiTietPhieuNhapSach]    Script Date: 15/07/2020 3:47:59 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ChiTietPhieuNhapSach](
	[CTPNS_ID] [int] NOT NULL,
	[IDPhieuNhapSach] [int] NULL,
	[IDSach] [int] NULL,
	[SoLuong] [int] NULL,
	[DonGia] [float] NULL,
 CONSTRAINT [PK_ChiTietPhieuNhapSach] PRIMARY KEY CLUSTERED
(
	[CTPNS_ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[HoaDon]    Script Date: 15/07/2020 3:47:59 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HoaDon](
	[HD_ID] [int] NOT NULL,
	[Ngay] [date] NULL,
	[NhanVien] [nvarchar](255) NULL,
	[TenKhachHang] [nvarchar](255) NULL,
	[GhiChu] [nvarchar](255) NULL,
 CONSTRAINT [PK_HoaDon] PRIMARY KEY CLUSTERED
(
	[HD_ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[LoaiSach]    Script Date: 15/07/2020 3:47:59 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[LoaiSach](
	[LS_ID] [int] NOT NULL,
	[Ten] [nvarchar](100) NULL,
	[MoTa] [nvarchar](255) NULL,
 CONSTRAINT [PK_LoaiSach] PRIMARY KEY CLUSTERED
(
	[LS_ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[NguoiDung]    Script Date: 15/07/2020 3:47:59 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[NguoiDung](
	[ND_ID] [int] NOT NULL,
	[TenDangNhap] [nvarchar](20) NULL,
	[MatKhau] [nvarchar](45) NULL,
	[HoTen] [nvarchar](255) NULL,
	[Email] [nvarchar](45) NULL,
	[DiaChi] [nvarchar](255) NULL,
	[NgaySinh] [date] NULL,
	[GioiTinh] [nvarchar](10) NULL,
 CONSTRAINT [PK_NguoiDung] PRIMARY KEY CLUSTERED
(
	[ND_ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[PhieuNhapSach]    Script Date: 15/07/2020 3:47:59 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PhieuNhapSach](
	[PNS_ID] [int] NOT NULL,
	[GhiChu] [nvarchar](255) NULL,
	[Ngay] [date] NULL,
	[NhanVien] [nvarchar](255) NULL,
 CONSTRAINT [PK_PhieuNhapSach] PRIMARY KEY CLUSTERED
(
	[PNS_ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Sach]    Script Date: 15/07/2020 3:47:59 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Sach](
	[S_ID] [int] NOT NULL,
	[TieuDe] [nvarchar](255) NULL,
	[TacGia] [nvarchar](255) NULL,
	[NamXuatBan] [int] NULL,
	[TheLoai] [int] NULL,
	[MoTa] [nvarchar](255) NULL,
 CONSTRAINT [PK_Sach] PRIMARY KEY CLUSTERED
(
	[S_ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
INSERT [dbo].[LoaiSach] ([LS_ID], [Ten], [MoTa]) VALUES (1, N'Kinh tế', NULL)
INSERT [dbo].[LoaiSach] ([LS_ID], [Ten], [MoTa]) VALUES (2, N'Văn học', NULL)
INSERT [dbo].[NguoiDung] ([ND_ID], [TenDangNhap], [MatKhau], [HoTen], [Email], [DiaChi], [NgaySinh], [GioiTinh]) VALUES (1, N'admin', N'12345', N'Nguyễn Văn Thịnh', N'thinhnv@hufi.edu.vn', NULL, NULL, NULL)
INSERT [dbo].[NguoiDung] ([ND_ID], [TenDangNhap], [MatKhau], [HoTen], [Email], [DiaChi], [NgaySinh], [GioiTinh]) VALUES (2, N'huunt', N'12345', N'Nguyễn Thế Hữu', N'huunt@hufi.edu.vn', NULL, NULL, NULL)
ALTER TABLE [dbo].[ChiTietHoaDon]  WITH CHECK ADD  CONSTRAINT [FK_ChiTietHoaDon_HoaDon] FOREIGN KEY([IDHoaDon])
REFERENCES [dbo].[HoaDon] ([HD_ID])
GO
ALTER TABLE [dbo].[ChiTietHoaDon] CHECK CONSTRAINT [FK_ChiTietHoaDon_HoaDon]
GO
ALTER TABLE [dbo].[ChiTietHoaDon]  WITH CHECK ADD  CONSTRAINT [FK_ChiTietHoaDon_Sach] FOREIGN KEY([IDSach])
REFERENCES [dbo].[Sach] ([S_ID])
GO
ALTER TABLE [dbo].[ChiTietHoaDon] CHECK CONSTRAINT [FK_ChiTietHoaDon_Sach]
GO
ALTER TABLE [dbo].[ChiTietPhieuNhapSach]  WITH CHECK ADD  CONSTRAINT [FK_ChiTietPhieuNhapSach_PhieuNhapSach] FOREIGN KEY([IDPhieuNhapSach])
REFERENCES [dbo].[PhieuNhapSach] ([PNS_ID])
GO
ALTER TABLE [dbo].[ChiTietPhieuNhapSach] CHECK CONSTRAINT [FK_ChiTietPhieuNhapSach_PhieuNhapSach]
GO
ALTER TABLE [dbo].[ChiTietPhieuNhapSach]  WITH CHECK ADD  CONSTRAINT [FK_ChiTietPhieuNhapSach_Sach] FOREIGN KEY([IDSach])
REFERENCES [dbo].[Sach] ([S_ID])
GO
ALTER TABLE [dbo].[ChiTietPhieuNhapSach] CHECK CONSTRAINT [FK_ChiTietPhieuNhapSach_Sach]
GO
ALTER TABLE [dbo].[Sach]  WITH CHECK ADD  CONSTRAINT [FK_Sach_LoaiSach] FOREIGN KEY([TheLoai])
REFERENCES [dbo].[LoaiSach] ([LS_ID])
GO
ALTER TABLE [dbo].[Sach] CHECK CONSTRAINT [FK_Sach_LoaiSach]
GO
USE [master]
GO
ALTER DATABASE [QL_NhaSach] SET  READ_WRITE
GO
