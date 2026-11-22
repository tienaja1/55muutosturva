 

CREATE DATABASE Kirjasto;
GO
USE Kirjasto;
GO

CREATE TABLE dbo.Asiakkaat (
    AsiakasId     INT IDENTITY(1,1) PRIMARY KEY,
    Etunimi       NVARCHAR(50)  NOT NULL,
    Sukunimi      NVARCHAR(50)  NOT NULL,
    Sahkoposti    NVARCHAR(100) NULL UNIQUE,
    Puhelin       NVARCHAR(20)  NULL,
    Liittymispvm  DATE          NOT NULL DEFAULT CAST(SYSDATETIME() AS DATE)
);

CREATE TABLE dbo.Kirjat (
    KirjaId       INT IDENTITY(1,1) PRIMARY KEY,
    Nimi          NVARCHAR(200) NOT NULL,
    Kirjailija    NVARCHAR(100) NOT NULL,
    ISBN          NVARCHAR(20)  NULL UNIQUE,
    Julkaisuvuosi SMALLINT      NULL,
    Kpl           INT           NOT NULL DEFAULT 1,
    CONSTRAINT CK_Kirjat_Kpl CHECK (Kpl >= 0)
);

CREATE TABLE dbo.Lainat (
    LainaId       INT IDENTITY(1,1) PRIMARY KEY,
    AsiakasId     INT  NOT NULL,
    KirjaId       INT  NOT NULL,
    Lainauspvm    DATE NOT NULL DEFAULT CAST(SYSDATETIME() AS DATE),
    Erapaiva      DATE NOT NULL,
    Palautuspvm   DATE NULL,
    CONSTRAINT FK_Lainat_Asiakkaat FOREIGN KEY (AsiakasId) REFERENCES dbo.Asiakkaat(AsiakasId),
    CONSTRAINT FK_Lainat_Kirjat    FOREIGN KEY (KirjaId)   REFERENCES dbo.Kirjat(KirjaId),
    CONSTRAINT CK_Lainat_Erapaiva  CHECK (Erapaiva >= Lainauspvm)
);

CREATE TABLE dbo.Varaukset (
    VarausId      INT IDENTITY(1,1) PRIMARY KEY,
    AsiakasId     INT  NOT NULL,
    KirjaId       INT  NOT NULL,
    Varauspvm     DATE NOT NULL DEFAULT CAST(SYSDATETIME() AS DATE),
    Tila          NVARCHAR(20) NOT NULL DEFAULT N'Voimassa',
    CONSTRAINT FK_Varaukset_Asiakkaat FOREIGN KEY (AsiakasId) REFERENCES dbo.Asiakkaat(AsiakasId),
    CONSTRAINT FK_Varaukset_Kirjat    FOREIGN KEY (KirjaId)   REFERENCES dbo.Kirjat(KirjaId),
    CONSTRAINT CK_Varaukset_Tila CHECK (Tila IN (N'Voimassa', N'Noudettu', N'Peruttu'))
);

CREATE INDEX IX_Lainat_AsiakasId    ON dbo.Lainat(AsiakasId);
CREATE INDEX IX_Lainat_KirjaId      ON dbo.Lainat(KirjaId);
CREATE INDEX IX_Varaukset_AsiakasId ON dbo.Varaukset(AsiakasId);
CREATE INDEX IX_Varaukset_KirjaId   ON dbo.Varaukset(KirjaId);


INSERT INTO dbo.Asiakkaat (Etunimi, Sukunimi, Sahkoposti)
VALUES (N'Maija', N'Meikäläinen', N'maija@example.com');

INSERT INTO dbo.Kirjat (Nimi, Kirjailija, ISBN, Julkaisuvuosi, Kpl)
VALUES (N'Tuntematon sotilas', N'Väinö Linna', N'9789510000000', 1954, 3);

INSERT INTO dbo.Lainat (AsiakasId, KirjaId, Erapaiva)
VALUES (1, 1, DATEADD(DAY, 28, CAST(SYSDATETIME() AS DATE)));

INSERT INTO dbo.Varaukset (AsiakasId, KirjaId, Varauspvm)
VALUES (1, 1, DATEADD(DAY, 28, CAST(SYSDATETIME() AS DATE)));




INSERT INTO dbo.Asiakkaat (Etunimi, Sukunimi, Sahkoposti)
VALUES (N'Vesa', N'Ihalainen', N'vesa@example.com');

INSERT INTO dbo.Kirjat (Nimi, Kirjailija, ISBN, Julkaisuvuosi, Kpl)
VALUES (N'Sinuhe Egyptiläinen', N'Mika Waltari', N'9782310000000', 1952, 3);

INSERT INTO dbo.Kirjat (Nimi, Kirjailija, ISBN, Julkaisuvuosi, Kpl)
VALUES (N'Mikael Karvajalka', N'Mika Waltari', N'9783450000000', 1957, 3);

INSERT INTO dbo.Asiakkaat (Etunimi, Sukunimi, Sahkoposti)
VALUES (N'Kalevi', N'Leiviskä', N'kalevi@example.com');

INSERT INTO dbo.Asiakkaat (Etunimi, Sukunimi, Sahkoposti)
VALUES (N'Anneli', N'Lämsä', N'anneli@example.com');

INSERT INTO dbo.Kirjat (Nimi, Kirjailija, ISBN, Julkaisuvuosi, Kpl)
VALUES (N'Rikos ja Rangaistus', N'Fjodor Dostojevski', N'9786780000000', 1866, 5);

SELECT a.Etunimi, a.Sukunimi, k.Nimi, l.Varauspvm
FROM dbo.Varaukset l
JOIN dbo.Asiakkaat a ON a.AsiakasId = l.AsiakasId
JOIN dbo.Kirjat k    ON k.KirjaId   = l.KirjaId
WHERE l.Varauspvm IS NOT NULL;

SELECT a.Etunimi, a.Sukunimi, k.Nimi, l.Erapaiva
FROM dbo.Lainat l
JOIN dbo.Asiakkaat a ON a.AsiakasId = l.AsiakasId
JOIN dbo.Kirjat k    ON k.KirjaId   = l.KirjaId
WHERE l.Palautuspvm IS NULL;

SELECT * FROM dbo.Kirjat;

SELECT * From dbo.varaukset;

SELECT * From dbo.Lainat; 

SELECT * From dbo.Varaukset; 

SELECT * From dbo.Asiakkaat; 

--use Kirjasto;
CREATE TABLE dbo.Kirjailijat (
    KirjailijaId  INT IDENTITY(1,1) PRIMARY KEY,
    Etunimi       NVARCHAR(50) NOT NULL,
    Sukunimi      NVARCHAR(50) NOT NULL,
    Syntymavuosi  SMALLINT NULL
);

CREATE TABLE dbo.KirjaKirjailija (
    KirjaId      INT NOT NULL,
    KirjailijaId INT NOT NULL,
    CONSTRAINT PK_KirjaKirjailija PRIMARY KEY (KirjaId, KirjailijaId),
    CONSTRAINT FK_KK_Kirjat      FOREIGN KEY (KirjaId)      REFERENCES dbo.Kirjat(KirjaId),
    CONSTRAINT FK_KK_Kirjailijat FOREIGN KEY (KirjailijaId) REFERENCES dbo.Kirjailijat(KirjailijaId)
);

select * from dbo.kirjailijat; 

INSERT INTO dbo.Kirjailijat (Etunimi, Sukunimi, syntymavuosi)
VALUES (N'Väinö', N'Linna', N'1920');

INSERT INTO dbo.Kirjailijat (Etunimi, Sukunimi, syntymavuosi)
VALUES (N'Mika', N'Waltari', N'1908');

INSERT INTO dbo.Kirjailijat (Etunimi, Sukunimi, syntymavuosi)
VALUES (N'Fjodor', N'Dostojevski', N'1881');

select * from dbo.Kirjakirjailija;

INSERT INTO dbo.KirjaKirjailija (KirjaId, KirjailijaId)
VALUES (1, 1), (2, 2);

INSERT INTO dbo.KirjaKirjailija (KirjaId, KirjailijaId)
VALUES (3, 2);

INSERT INTO dbo.KirjaKirjailija (KirjaId, KirjailijaId)
VALUES (4, 3);


CREATE OR ALTER TRIGGER dbo.trg_Lainat_Insert
ON dbo.Lainat
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

    -- Yhteenveto lisätyistä lainoista kirjoittain (käsittelee myös usean rivin lisäyksen)
    ;WITH Uudet AS (
        SELECT KirjaId, COUNT(*) AS Maara
        FROM inserted
        GROUP BY KirjaId
    )
    -- Tarkistus: onko kappaleita tarpeeksi?
    SELECT 1
    FROM dbo.Kirjat k
    JOIN Uudet u ON u.KirjaId = k.KirjaId
    WHERE k.Kpl < u.Maara;

    IF @@ROWCOUNT > 0
    BEGIN
        ROLLBACK TRANSACTION;
        THROW 50001, N'Kirjaa ei ole saatavilla: kappalemäärä ei riitä lainaan.', 1;
    END;

    -- Vähennä kappalemäärää
    UPDATE k
    SET k.Kpl = k.Kpl - u.Maara
    FROM dbo.Kirjat k
    JOIN (SELECT KirjaId, COUNT(*) AS Maara FROM inserted GROUP BY KirjaId) u
        ON u.KirjaId = k.KirjaId;
END;
GO

CREATE OR ALTER TRIGGER dbo.trg_Lainat_Palautus
ON dbo.Lainat
AFTER UPDATE
AS
BEGIN
    SET NOCOUNT ON;

    IF NOT UPDATE(Palautuspvm) RETURN;

    -- Vain rivit, joissa palautus kirjattiin nyt (NULL -> arvo)
    UPDATE k
    SET k.Kpl = k.Kpl + u.Maara
    FROM dbo.Kirjat k
    JOIN (
        SELECT i.KirjaId, COUNT(*) AS Maara
        FROM inserted i
        JOIN deleted d ON d.LainaId = i.LainaId
        WHERE d.Palautuspvm IS NULL
          AND i.Palautuspvm IS NOT NULL
        GROUP BY i.KirjaId
    ) u ON u.KirjaId = k.KirjaId;
END;
GO

INSERT INTO dbo.Lainat (AsiakasId, KirjaId, Erapaiva)
VALUES (1, 1, DATEADD(DAY, 28, CAST(SYSDATETIME() AS DATE)));

SELECT KirjaId, Nimi, Kpl FROM dbo.Kirjat WHERE KirjaId = 1;   -- Kpl väheni yhdellä


UPDATE dbo.Lainat
SET Palautuspvm = CAST(SYSDATETIME() AS DATE)
WHERE LainaId = 1;

SELECT KirjaId, Nimi, Kpl FROM dbo.Kirjat WHERE KirjaId = 1;   -- Kpl palasi


---yksinkertainen haku kursoria käyttäen 

DECLARE @KirjaId INT,
        @Nimi NVARCHAR(200),
        @Kpl INT;

DECLARE kirja_cursor CURSOR LOCAL FAST_FORWARD FOR
    SELECT KirjaId, Nimi, Kpl
    FROM dbo.Kirjat
    ORDER BY Nimi;

OPEN kirja_cursor;

FETCH NEXT FROM kirja_cursor INTO @KirjaId, @Nimi, @Kpl;

WHILE @@FETCH_STATUS = 0
BEGIN
    PRINT CONCAT('Kirja ', @KirjaId, ': ', @Nimi, ' (', @Kpl, ' kpl)');

    FETCH NEXT FROM kirja_cursor INTO @KirjaId, @Nimi, @Kpl;
END;

CLOSE kirja_cursor;
DEALLOCATE kirja_cursor;