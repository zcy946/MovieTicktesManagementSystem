-- 创建数据库
CREATE DATABASE movieticktesmanagementsystem;
USE movieticktesmanagementsystem;
-- ---------------------------------------------------------------------------------------------------------------------------------------------
-- 创建表
-- 电影表（Movies）:
	-- 电影ID（MovieID）
	-- 电影名称（MovieName）
	-- 上映日期（ReleaseDate）
	-- 时长（Duration）
	-- 导演（Director）
	-- 类型（Genre）
CREATE TABLE Movies (
    MovieID INT PRIMARY KEY,
    MovieName VARCHAR(255) NOT NULL,
    ReleaseDate DATE,
    Duration INT,
    Director VARCHAR(255),
    Genre VARCHAR(255)
);

-- 影院表（Cinemas）:
	-- 影院ID（CinemaID）
	-- 影院名称（CinemaName）
	-- 地址（Address）
CREATE TABLE Cinemas (
    CinemaID INT PRIMARY KEY,
    CinemaName VARCHAR(255) NOT NULL,
    Address VARCHAR(255)
);

-- 放映厅表（Auditoriums）:
	-- 放映厅ID（AuditoriumID）
	-- 放映厅名称（AuditoriumName）
	-- 影院ID（CinemaID）
CREATE TABLE Auditoriums (
    AuditoriumID INT PRIMARY KEY,
    AuditoriumName VARCHAR(255) NOT NULL,
    CinemaID INT,
    FOREIGN KEY (CinemaID) REFERENCES Cinemas(CinemaID)
);

-- 场次表（Screenings）:
	-- 场次ID（ScreeningID）
	-- 电影ID（MovieID）
	-- 放映厅ID（AuditoriumID）
	-- 开始时间（StartTime）
CREATE TABLE Screenings (
    ScreeningID INT PRIMARY KEY,
    MovieID INT,
    AuditoriumID INT,
    StartTime DATETIME
);

-- 订单表（Orders）:
-- 订单ID（OrderID）
-- 场次ID（ScreeningID）
-- 座位号（SeatNumber）
-- 用户ID（UserID）
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    ScreeningID INT,
    SeatNumber VARCHAR(10),
    UserID INT
);
-- ---------------------------------------------------------------------------------------------------------------------------------------------
-- 添加数据
-- 电影数据 (Movies):
INSERT INTO Movies (MovieID, MovieName, ReleaseDate, Duration, Director, Genre)
VALUES
    (1, '流浪地球', '2019-02-05', 125, '郭帆', '科幻'),
    (2, '红海行动', '2018-02-16', 142, '林超贤', '动作'),
    (3, '战狼2', '2017-07-27', 123, '吴京', '动作');
SELECT * FROM Movies;

-- 影院数据 (Cinemas):
INSERT INTO Cinemas (CinemaID, CinemaName, Address)
VALUES
    (1, '星影影城', '北京市朝阳区'),
    (2, '银幕影城', '上海市徐汇区'),
    (3, '夜幕电影院', '广州市天河区');
SELECT * FROM Cinemas;    
    
-- 放映厅数据 (Auditoriums):
INSERT INTO Auditoriums (AuditoriumID, AuditoriumName, CinemaID)
VALUES
    (101, '1号放映厅', 1),
    (102, '2号放映厅', 2),
    (103, '3号放映厅', 3);
SELECT * FROM Auditoriums;     
    
-- 场次数据 (Screenings):
INSERT INTO Screenings (ScreeningID, MovieID, AuditoriumID, StartTime)
VALUES
    (1001, 1, 101, '2023-12-10 18:00:00'),
    (1002, 2, 102, '2023-12-10 20:30:00'),
    (1003, 3, 103, '2023-12-11 15:45:00');
SELECT * FROM Screenings;     
    
-- 订单数(Orders):
INSERT INTO Orders (OrderID, ScreeningID, SeatNumber, UserID)
VALUES
   (2001, 1001, 'A1', 101),
   (2002, 1002, 'B3', 102),
   (2003, 1003, 'C2', 103);
SELECT * FROM Orders;  
-- ---------------------------------------------------------------------------------------------------------------------------------------------
USE movieticktesmanagementsystem;
SHOW TABLES;
DROP TABLE Movies;
CREATE TABLE Movies (
    MovieID INT PRIMARY KEY,
    MovieName VARCHAR(255) NOT NULL,
    ReleaseDate DATE,
    Duration INT,
    Director VARCHAR(255),
    Genre VARCHAR(255)
);
INSERT INTO Movies (MovieID, MovieName, ReleaseDate, Duration, Director, Genre)
VALUES
    (1, '流浪地球', '2019-02-05', 125, '郭帆', '科幻'),
    (2, '红海行动', '2018-02-16', 142, '林超贤', '动作'),
    (3, '战狼2', '2017-07-27', 123, '吴京', '动作');
SELECT * FROM Movies;


INSERT INTO Movies (MovieID, MovieName, ReleaseDate, Duration, Director, Genre) VALUES (5, '三毛', NULL, NULL, NULL, NULL);
DELETE FROM Movies WHERE MovieID = 3;

DELETE FROM Movies WHERE MovieID = 5;
SELECT * FROM Movies;

DELETE FROM Movies WHERE MovieID = 7;
DESC Movies;
SELECT * FROM Movies WHERE MovieID = 3;
