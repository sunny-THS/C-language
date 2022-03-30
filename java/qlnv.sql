IF NOT EXISTS(SELECT * FROM sys.databases WHERE name='QL_NHANVIEN')
BEGIN
	CREATE DATABASE [QL_NHANVIEN]
END
GO
USE [QL_NHANVIEN]
GO
/****** Object:  Table [dbo].[NhanVien]    Script Date: 13/05/2019 8:07:25 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[NhanVien](
	[MaNV] [int] NOT NULL,
	[HoTen] [nvarchar](50) NULL,
	[Phai] [char](1) NULL,
	[NgaySinh] [datetime] NULL,
	[DiaChi] [nvarchar](100) NULL,
	[Luong] [float] NULL,
	[Phong] [int] NULL,
	[TrangThai] [bit] NULL,
 CONSTRAINT [PK_NhanVien] PRIMARY KEY CLUSTERED
(
	[MaNV] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[PhongBan]    Script Date: 13/05/2019 8:07:25 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PhongBan](
	[MaPHG] [int] IDENTITY(1,1) NOT NULL,
	[TenPHG] [nvarchar](50) NULL,
 CONSTRAINT [PK_PhongBan] PRIMARY KEY CLUSTERED
(
	[MaPHG] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1000, N'Fuller H. Kemp', N'M', CAST(0x0000735100000000 AS DateTime), N'Canada', 39000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1001, N'Skyler M. Beach', N'F', CAST(0x000076F000000000 AS DateTime), N'Canada', 60000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1002, N'Tanisha L. Sloan', N'M', CAST(0x00007A7500000000 AS DateTime), N'Canada', 48000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1003, N'Kylan N. Wise', N'M', CAST(0x00007B5000000000 AS DateTime), N'Canada', 47000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1004, N'Tatiana J. Davenport', N'F', CAST(0x00007CCF00000000 AS DateTime), N'United States', 64000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1005, N'Maggie S. Velazquez', N'M', CAST(0x0000753800000000 AS DateTime), N'United States', 69000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1006, N'Ivy N. Moran', N'M', CAST(0x0000778600000000 AS DateTime), N'Canada', 21000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1007, N'Zorita Q. Clayton', N'F', CAST(0x0000752A00000000 AS DateTime), N'United States', 55000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1008, N'Melyssa P. Wong', N'F', CAST(0x00007A8D00000000 AS DateTime), N'United States', 21000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1009, N'Unity L. Kirk', N'M', CAST(0x0000759600000000 AS DateTime), N'Canada', 57000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1010, N'Kieran W. Mckee', N'F', CAST(0x000075A100000000 AS DateTime), N'United States', 51000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1011, N'Jorden W. Sherman', N'F', CAST(0x000077D300000000 AS DateTime), N'Canada', 49000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1012, N'Ariana O. Kent', N'F', CAST(0x00007A3800000000 AS DateTime), N'United States', 42000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1013, N'Rhea A. Boone', N'F', CAST(0x0000757D00000000 AS DateTime), N'United States', 26000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1014, N'Keiko I. Bentley', N'F', CAST(0x00007B0D00000000 AS DateTime), N'United States', 50000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1015, N'Ralph P. Rush', N'M', CAST(0x00007AB800000000 AS DateTime), N'Canada', 50000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1016, N'Abbot Y. Manning', N'M', CAST(0x00007A6800000000 AS DateTime), N'United States', 56000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1017, N'Jessamine A. Austin', N'F', CAST(0x00007B3A00000000 AS DateTime), N'Canada', 32000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1018, N'Leroy E. Nelson', N'M', CAST(0x0000751900000000 AS DateTime), N'Canada', 28000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1019, N'Sylvia H. Phillips', N'F', CAST(0x0000782D00000000 AS DateTime), N'Canada', 36000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1020, N'Nola T. Wade', N'M', CAST(0x0000755200000000 AS DateTime), N'United States', 65000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1021, N'Maggy P. Mcintyre', N'M', CAST(0x000073FA00000000 AS DateTime), N'United States', 78000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1022, N'Gloria Y. Weber', N'M', CAST(0x0000753700000000 AS DateTime), N'Canada', 23000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1023, N'Maggie G. Maynard', N'F', CAST(0x00007D1300000000 AS DateTime), N'United States', 34000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1024, N'Graham L. Yates', N'M', CAST(0x00007A8C00000000 AS DateTime), N'United States', 22000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1025, N'Hayley L. Lindsey', N'F', CAST(0x0000766300000000 AS DateTime), N'Canada', 32000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1026, N'Fritz X. Holman', N'F', CAST(0x00007C1800000000 AS DateTime), N'Canada', 31000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1027, N'Lunea G. Leon', N'M', CAST(0x00007CA700000000 AS DateTime), N'United States', 50000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1028, N'Brittany R. Pruitt', N'F', CAST(0x00007AF700000000 AS DateTime), N'United States', 55000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1029, N'Dexter V. Cunningham', N'M', CAST(0x00007A3500000000 AS DateTime), N'Canada', 41000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1030, N'Maris V. Melton', N'F', CAST(0x0000786E00000000 AS DateTime), N'United States', 26000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1031, N'Helen E. Roy', N'F', CAST(0x0000787400000000 AS DateTime), N'Canada', 48000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1032, N'Jakeem B. Armstrong', N'M', CAST(0x00007A8800000000 AS DateTime), N'United States', 71000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1033, N'Brendan I. Dillon', N'F', CAST(0x00007A6F00000000 AS DateTime), N'United States', 24000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1034, N'Jescie Q. Sykes', N'F', CAST(0x000079DC00000000 AS DateTime), N'United States', 31000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1035, N'Yolanda B. Dillard', N'F', CAST(0x00007C5E00000000 AS DateTime), N'United States', 44000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1036, N'Wylie Y. Chavez', N'F', CAST(0x000078DE00000000 AS DateTime), N'Canada', 39000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1037, N'Deborah N. Bright', N'F', CAST(0x0000754A00000000 AS DateTime), N'Canada', 56000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1038, N'Beatrice J. Conley', N'F', CAST(0x0000736700000000 AS DateTime), N'Canada', 44000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1039, N'Ignacia R. Castaneda', N'F', CAST(0x0000779300000000 AS DateTime), N'United States', 66000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1040, N'TaShya A. Curtis', N'M', CAST(0x000075FA00000000 AS DateTime), N'United States', 66000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1041, N'Quinn G. Lott', N'F', CAST(0x0000739600000000 AS DateTime), N'Canada', 69000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1042, N'Zorita C. Dillon', N'F', CAST(0x000076B600000000 AS DateTime), N'United States', 33000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1043, N'Sylvester R. Henry', N'M', CAST(0x000078E200000000 AS DateTime), N'Canada', 77000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1044, N'Garrison B. Vang', N'M', CAST(0x0000798600000000 AS DateTime), N'United States', 24000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1045, N'Germane O. Bond', N'M', CAST(0x0000799A00000000 AS DateTime), N'United States', 48000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1046, N'Kathleen G. Keller', N'F', CAST(0x000076DC00000000 AS DateTime), N'United States', 20000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1047, N'Wylie A. Frazier', N'M', CAST(0x000077CE00000000 AS DateTime), N'Canada', 77000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1048, N'Rachel D. Roberson', N'M', CAST(0x00007CD000000000 AS DateTime), N'United States', 78000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1049, N'Axel F. Newman', N'M', CAST(0x0000735400000000 AS DateTime), N'Canada', 56000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1050, N'Chadwick F. Black', N'M', CAST(0x0000753F00000000 AS DateTime), N'Canada', 72000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1051, N'Garth C. Vazquez', N'F', CAST(0x0000739400000000 AS DateTime), N'United States', 70000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1052, N'Fiona H. Yang', N'F', CAST(0x00007A9C00000000 AS DateTime), N'United States', 42000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1053, N'Austin X. Buckley', N'F', CAST(0x0000739500000000 AS DateTime), N'United States', 63000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1054, N'Margaret P. Cummings', N'M', CAST(0x000077F700000000 AS DateTime), N'Canada', 48000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1055, N'Todd R. Jimenez', N'F', CAST(0x000076BD00000000 AS DateTime), N'Canada', 52000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1056, N'Carol I. Finley', N'F', CAST(0x00007B0500000000 AS DateTime), N'United States', 34000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1057, N'Robert W. Gordon', N'F', CAST(0x000076F800000000 AS DateTime), N'Canada', 73000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1058, N'Chaney S. Hinton', N'F', CAST(0x0000774200000000 AS DateTime), N'United States', 25000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1059, N'Deirdre O. Berger', N'M', CAST(0x0000774800000000 AS DateTime), N'United States', 54000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1060, N'Pandora P. Bray', N'M', CAST(0x00007A3200000000 AS DateTime), N'Canada', 21000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1061, N'Tate T. Becker', N'F', CAST(0x00007A1800000000 AS DateTime), N'United States', 56000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1062, N'Anthony E. Armstrong', N'M', CAST(0x0000765200000000 AS DateTime), N'Canada', 54000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1063, N'Hayley O. Richard', N'F', CAST(0x000074F900000000 AS DateTime), N'Canada', 38000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1064, N'Trevor R. Vance', N'M', CAST(0x00007B1200000000 AS DateTime), N'United States', 73000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1065, N'TaShya U. Cochran', N'M', CAST(0x0000775900000000 AS DateTime), N'United States', 25000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1066, N'Cruz S. Barry', N'F', CAST(0x00007AC600000000 AS DateTime), N'United States', 76000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1067, N'Juliet M. Holcomb', N'F', CAST(0x0000747400000000 AS DateTime), N'United States', 68000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1068, N'Kelly W. Suarez', N'M', CAST(0x00007B2300000000 AS DateTime), N'United States', 37000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1069, N'Ariana O. Rodriguez', N'F', CAST(0x0000736200000000 AS DateTime), N'United States', 47000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1070, N'Beverly E. Robinson', N'F', CAST(0x000078A000000000 AS DateTime), N'United States', 25000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1071, N'Cameron L. Rutledge', N'F', CAST(0x0000755200000000 AS DateTime), N'United States', 59000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1072, N'Cassidy Z. Davidson', N'F', CAST(0x0000792600000000 AS DateTime), N'United States', 80000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1073, N'Madonna G. Marquez', N'M', CAST(0x0000760A00000000 AS DateTime), N'Canada', 38000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1074, N'Carter P. Santana', N'M', CAST(0x0000745D00000000 AS DateTime), N'United States', 77000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1075, N'Leah Q. Morrison', N'F', CAST(0x00007A5000000000 AS DateTime), N'Canada', 21000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1076, N'Kasimir C. Nichols', N'M', CAST(0x0000796300000000 AS DateTime), N'United States', 25000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1077, N'Ina B. Wolf', N'M', CAST(0x00007CAB00000000 AS DateTime), N'Canada', 62000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1078, N'Candice D. Rice', N'F', CAST(0x00007CB700000000 AS DateTime), N'United States', 41000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1079, N'Aaron V. Jensen', N'F', CAST(0x00007A7100000000 AS DateTime), N'Canada', 49000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1080, N'Ezra M. Conrad', N'M', CAST(0x00007BE900000000 AS DateTime), N'Canada', 34000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1081, N'Jason P. Freeman', N'M', CAST(0x000075A300000000 AS DateTime), N'Canada', 66000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1082, N'Charde Y. Albert', N'F', CAST(0x00007CBB00000000 AS DateTime), N'Canada', 66000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1083, N'Kareem Q. Key', N'M', CAST(0x0000740700000000 AS DateTime), N'United States', 65000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1084, N'Tana Y. Wilcox', N'F', CAST(0x0000754900000000 AS DateTime), N'Canada', 30000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1085, N'Bertha Y. Robbins', N'M', CAST(0x00007B8100000000 AS DateTime), N'United States', 68000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1086, N'Medge I. Wilkinson', N'F', CAST(0x0000736100000000 AS DateTime), N'United States', 20000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1087, N'Brielle S. Clarke', N'F', CAST(0x000074DB00000000 AS DateTime), N'United States', 31000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1088, N'Francis C. Maldonado', N'F', CAST(0x0000775200000000 AS DateTime), N'United States', 36000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1089, N'Benedict S. Pittman', N'M', CAST(0x0000733900000000 AS DateTime), N'United States', 66000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1090, N'Kitra M. Williamson', N'F', CAST(0x0000782E00000000 AS DateTime), N'United States', 20000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1091, N'Graiden Z. Chen', N'F', CAST(0x00007AC000000000 AS DateTime), N'Canada', 55000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1092, N'Edan X. Beard', N'M', CAST(0x000079CD00000000 AS DateTime), N'Canada', 61000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1093, N'Walter Y. Santos', N'M', CAST(0x00007AA000000000 AS DateTime), N'United States', 57000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1094, N'Evangeline U. Petty', N'M', CAST(0x000073A800000000 AS DateTime), N'United States', 33000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1095, N'Todd Z. Allison', N'M', CAST(0x000079E000000000 AS DateTime), N'United States', 78000, 5, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1096, N'Ali P. Chandler', N'F', CAST(0x000076D200000000 AS DateTime), N'United States', 62000, 4, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1097, N'Cameran F. Morse', N'F', CAST(0x000076AE00000000 AS DateTime), N'Canada', 46000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1098, N'Gage K. Chan', N'M', CAST(0x00007B3300000000 AS DateTime), N'Canada', 48000, 1, NULL)
INSERT [dbo].[NhanVien] ([MaNV], [HoTen], [Phai], [NgaySinh], [DiaChi], [Luong], [Phong], [TrangThai]) VALUES (1099, N'Avye N. Roman', N'F', CAST(0x00007C2500000000 AS DateTime), N'United States', 69000, 1, NULL)
GO
SET IDENTITY_INSERT [dbo].[PhongBan] ON

INSERT [dbo].[PhongBan] ([MaPHG], [TenPHG]) VALUES (1, N'Phong A')
INSERT [dbo].[PhongBan] ([MaPHG], [TenPHG]) VALUES (2, N'Phong B')
INSERT [dbo].[PhongBan] ([MaPHG], [TenPHG]) VALUES (3, N'Phong C')
INSERT [dbo].[PhongBan] ([MaPHG], [TenPHG]) VALUES (4, N'Phong D')
INSERT [dbo].[PhongBan] ([MaPHG], [TenPHG]) VALUES (5, N'Phong E')
INSERT [dbo].[PhongBan] ([MaPHG], [TenPHG]) VALUES (6, N'Phong F')
INSERT [dbo].[PhongBan] ([MaPHG], [TenPHG]) VALUES (7, N'Phong G')
INSERT [dbo].[PhongBan] ([MaPHG], [TenPHG]) VALUES (8, N'Phong H')
INSERT [dbo].[PhongBan] ([MaPHG], [TenPHG]) VALUES (9, N'Phòng I')
SET IDENTITY_INSERT [dbo].[PhongBan] OFF
ALTER TABLE [dbo].[NhanVien]  WITH CHECK ADD  CONSTRAINT [FK_NhanVien_PhongBan] FOREIGN KEY([Phong])
REFERENCES [dbo].[PhongBan] ([MaPHG])
GO
ALTER TABLE [dbo].[NhanVien] CHECK CONSTRAINT [FK_NhanVien_PhongBan]
GO
