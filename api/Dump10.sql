CREATE DATABASE  IF NOT EXISTS `pankkiautomaatti` /*!40100 DEFAULT CHARACTER SET utf8 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `pankkiautomaatti`;
-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: pankkiautomaatti
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `idAsiakas` int NOT NULL AUTO_INCREMENT,
  `Asiakastunnus` int NOT NULL,
  `Nimi` varchar(45) DEFAULT NULL,
  `Osoite` varchar(45) DEFAULT NULL,
  `puh` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idAsiakas`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,1,'Seppo','Oulu','010'),(2,2,'Teppo','Kemi','020'),(3,3,'Matti','Helsiki','030');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti`
--

DROP TABLE IF EXISTS `kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti` (
  `ID` int NOT NULL AUTO_INCREMENT,
  `idKortti` int NOT NULL,
  `pin` varchar(255) NOT NULL,
  `Tili_idTili` int NOT NULL,
  `Asiakas_idAsiakas` int NOT NULL,
  `Tila` int NOT NULL,
  `Lukittu` int NOT NULL,
  PRIMARY KEY (`ID`,`Tili_idTili`,`Asiakas_idAsiakas`),
  KEY `fk_Tili_has_Asiakas_Asiakas1_idx` (`Asiakas_idAsiakas`),
  KEY `fk_Tili_has_Asiakas_Tili_idx` (`Tili_idTili`),
  CONSTRAINT `fk_Tili_has_Asiakas_Asiakas1` FOREIGN KEY (`Asiakas_idAsiakas`) REFERENCES `asiakas` (`idAsiakas`),
  CONSTRAINT `fk_Tili_has_Asiakas_Tili` FOREIGN KEY (`Tili_idTili`) REFERENCES `tili` (`idTili`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (1,5678,'$2a$10$bND0ToMFa6L23wYqvtwCaukEdm6iWLLBXstKNntB0uVTi.DkcTVci',2,2,1,0),(2,2345,'$2a$10$XTq1RgQZZDSvt82U42REROd4of/1yfbXBi58S57AS7EKg0r99Fs7m',3,3,1,0),(5,5432,'$2a$10$GqC1yusHC2zgUHjHG9eVZOpHse7IHg.ZiuvTUVrYKs1l62d4MVwuu',1,1,1,0),(9,5432,'$2a$10$oFi4CoPUy45wrAOT//lm..bWwmyjAs98O1olstu3vUVgBi.h.9iBC',4,1,0,0);
/*!40000 ALTER TABLE `kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `idTili` int NOT NULL AUTO_INCREMENT,
  `Tilinumero` int NOT NULL,
  `Saldo` int NOT NULL,
  `Tyyppi` varchar(45) NOT NULL,
  `Luottoraja` varchar(45) NOT NULL,
  PRIMARY KEY (`idTili`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
INSERT INTO `tili` VALUES (1,1,28476,'Debit','0'),(2,2,600,'Debit','0'),(3,3,250,'Debit','0'),(4,4,999,'Credit','1000');
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tilitapahtumat`
--

DROP TABLE IF EXISTS `tilitapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilitapahtumat` (
  `idTilitapahtumat` int NOT NULL AUTO_INCREMENT,
  `aika` datetime NOT NULL,
  `Tapahtuma` varchar(45) NOT NULL,
  `Maara` int NOT NULL,
  `Tili_idTili` int NOT NULL,
  PRIMARY KEY (`idTilitapahtumat`),
  KEY `fk_Tilitapahtumat_Tili1_idx` (`Tili_idTili`),
  CONSTRAINT `fk_Tilitapahtumat_Tili1` FOREIGN KEY (`Tili_idTili`) REFERENCES `tili` (`idTili`)
) ENGINE=InnoDB AUTO_INCREMENT=160 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
INSERT INTO `tilitapahtumat` VALUES (1,'2021-11-28 13:31:10','nosto',9,2),(4,'2021-11-28 13:39:35','nosto',2,1),(5,'2021-11-28 13:54:42','nosto',1,1),(6,'2021-11-28 13:54:59','nosto',1,1),(7,'2021-11-28 13:55:11','nosto',1,1),(8,'2021-11-28 14:22:26','nosto',1,1),(9,'2021-11-28 14:33:23','nosto',1,1),(10,'2021-11-28 15:33:45','nosto',1,1),(11,'2021-11-28 15:34:15','nosto',1,2),(12,'2021-11-28 15:34:25','nosto',1,2),(13,'2021-11-28 16:03:45','nosto',1,1),(14,'2021-11-28 16:08:50','nosto',1,1),(15,'2021-11-28 16:09:36','nosto',1,1),(16,'2021-11-29 13:17:38','nosto',1,1),(17,'2021-11-30 10:28:36','nosto',1,1),(18,'2021-11-30 10:39:30','pano',2,1),(19,'2021-11-30 10:56:16','pano',1,1),(20,'2021-11-30 10:56:27','pano',1,1),(21,'2021-11-30 10:56:28','pano',1,1),(22,'2021-11-30 10:56:28','pano',1,1),(23,'2021-11-30 10:56:28','pano',1,1),(24,'2021-11-30 10:56:28','pano',1,1),(25,'2021-11-30 10:56:28','pano',1,1),(26,'2021-11-30 10:56:28','pano',1,1),(27,'2021-11-30 10:56:28','pano',1,1),(28,'2021-11-30 10:56:48','pano',1,1),(29,'2021-11-30 11:04:17','pano',1,1),(30,'2021-11-30 11:20:36','pano',1,1),(31,'2021-11-30 11:25:41','pano',1,1),(32,'2021-11-30 11:27:47','pano',1,1),(33,'2021-11-30 11:29:28','pano',1,1),(34,'2021-11-30 11:29:30','pano',10,1),(35,'2021-11-30 11:32:43','pano',1,1),(36,'2021-11-30 11:32:46','pano',7,1),(37,'2021-11-30 11:43:07','pano',1,1),(38,'2021-11-30 11:43:29','pano',1,2),(39,'2021-11-30 12:00:32','pano',5,1),(40,'2021-11-30 12:02:22','pano',2,1),(41,'2021-11-30 12:02:45','pano',6345,2),(42,'2021-11-30 12:13:13','pano',3,1),(43,'2021-11-30 12:28:38','pano',4,1),(44,'2021-11-30 12:31:07','pano',1,1),(45,'2021-11-30 12:32:42','pano',2,1),(46,'2021-11-30 12:34:29','pano',23,1),(47,'2021-11-30 12:37:57','pano',2,1),(48,'2021-11-30 12:43:04','pano',1,1),(49,'2021-11-30 12:46:50','pano',3,1),(50,'2021-11-30 12:47:40','pano',1,1),(51,'2021-11-30 12:48:21','pano',2,1),(52,'2021-11-30 12:49:37','pano',3,1),(53,'2021-11-30 12:51:54','pano',3,1),(54,'2021-11-30 12:57:36','pano',3,1),(55,'2021-11-30 13:00:30','pano',3,1),(56,'2021-11-30 13:14:46','pano',1,1),(57,'2021-12-03 15:37:04','pano',20,1),(58,'2021-12-03 15:37:13','pano',200,1),(59,'2021-12-03 15:37:31','nosto',200,1),(60,'2021-12-04 13:40:42','pano',20,1),(61,'2021-12-04 13:40:42','pano',20,1),(62,'2021-12-04 13:40:42','pano',20,1),(63,'2021-12-04 13:40:42','pano',20,1),(64,'2021-12-04 13:40:42','pano',20,1),(65,'2021-12-04 13:40:43','pano',20,1),(66,'2021-12-04 13:40:43','pano',20,1),(67,'2021-12-04 13:40:43','pano',20,1),(68,'2021-12-04 13:40:43','pano',20,1),(69,'2021-12-04 13:40:49','nosto',200,1),(70,'2021-12-07 16:18:21','nosto',20,1),(71,'2021-12-07 18:33:43','nosto',1,2),(72,'2021-12-07 18:35:32','nosto',1,1),(73,'2021-12-07 18:35:52','nosto',13,4),(74,'2021-12-07 18:37:49','nosto',20,1),(75,'2021-12-07 18:40:43','nosto',20,1),(76,'2021-12-08 13:22:37','nosto',1,4),(77,'2021-12-08 13:40:53','pano',2,4),(78,'2021-12-08 13:41:23','pano',2,4),(79,'2021-12-08 13:51:58','pano',20,4),(80,'2021-12-08 14:45:16','nosto',20,1),(81,'2021-12-08 14:56:03','nosto',200,4),(82,'2021-12-08 15:03:53','nosto',40,4),(83,'2021-12-08 16:47:12','pano',34,1),(84,'2021-12-08 16:50:46','pano',3,1),(85,'2021-12-08 16:50:56','pano',4000,1),(86,'2021-12-08 16:50:57','pano',4000,1),(87,'2021-12-08 16:50:57','pano',4000,1),(88,'2021-12-08 16:50:57','pano',4000,1),(89,'2021-12-08 16:50:57','pano',4000,1),(90,'2021-12-08 16:50:57','pano',4000,1),(91,'2021-12-08 16:51:47','pano',2,1),(92,'2021-12-08 16:54:10','nosto',20,1),(93,'2021-12-08 16:54:19','nosto',50,1),(94,'2021-12-08 17:03:38','pano',45,1),(95,'2021-12-08 17:04:01','pano',500000,1),(96,'2021-12-08 17:04:20','nosto',100,1),(97,'2021-12-08 17:04:25','nosto',500000,1),(98,'2021-12-08 17:17:16','nosto',20,4),(99,'2021-12-08 17:17:27','nosto',1,4),(100,'2021-12-08 17:17:33','nosto',0,4),(101,'2021-12-08 17:22:13','pano',900,4),(102,'2021-12-08 17:22:29','pano',900,1),(103,'2021-12-08 17:22:36','pano',900,4),(104,'2021-12-08 17:24:21','pano',900,4),(105,'2021-12-08 17:24:25','pano',1,4),(106,'2021-12-08 17:24:31','pano',0,4),(107,'2021-12-08 17:24:36','pano',7,4),(108,'2021-12-08 17:24:44','pano',178587,4),(109,'2021-12-08 17:58:41','pano',45,4),(110,'2021-12-08 18:03:37','pano',4,4),(111,'2021-12-08 18:04:30','pano',3,1),(112,'2021-12-08 18:05:26','pano',1000,1),(113,'2021-12-08 18:06:17','pano',50,1),(114,'2021-12-08 18:06:33','pano',50,4),(115,'2021-12-08 18:08:00','pano',40,4),(116,'2021-12-08 18:08:27','pano',40,1),(117,'2021-12-08 18:08:33','pano',1000,1),(118,'2021-12-08 18:09:57','pano',60,1),(119,'2021-12-08 18:10:13','pano',2999,1),(120,'2021-12-08 18:10:41','pano',50,4),(121,'2021-12-08 18:12:15','nosto',50,4),(122,'2021-12-08 18:12:33','nosto',600,4),(123,'2021-12-08 18:12:55','nosto',20,4),(124,'2021-12-08 18:13:17','pano',100,4),(125,'2021-12-08 18:13:18','pano',100,4),(126,'2021-12-08 18:13:18','pano',100,4),(127,'2021-12-08 18:13:18','pano',100,4),(128,'2021-12-08 18:13:19','pano',100,4),(129,'2021-12-08 18:13:19','pano',100,4),(130,'2021-12-08 18:13:20','pano',100,4),(131,'2021-12-08 18:13:20','pano',100,4),(132,'2021-12-08 18:13:20','pano',100,4),(133,'2021-12-08 18:13:37','nosto',60,4),(134,'2021-12-08 18:13:41','pano',60,4),(135,'2021-12-08 18:13:42','pano',20,4),(136,'2021-12-08 18:13:52','pano',20,4),(137,'2021-12-08 18:13:52','pano',20,4),(138,'2021-12-08 18:13:53','pano',20,4),(139,'2021-12-08 18:19:25','nosto',60,1),(140,'2021-12-08 18:19:26','nosto',60,1),(141,'2021-12-08 18:19:27','nosto',200,1),(142,'2021-12-08 18:19:28','nosto',200,1),(143,'2021-12-08 18:19:28','nosto',200,1),(144,'2021-12-08 18:19:28','nosto',200,1),(145,'2021-12-08 18:19:28','nosto',200,1),(146,'2021-12-08 18:19:29','nosto',200,1),(147,'2021-12-08 18:19:31','nosto',80,1),(148,'2021-12-08 18:19:31','nosto',80,1),(149,'2021-12-08 18:19:31','nosto',80,1),(150,'2021-12-08 18:21:50','nosto',200,4),(151,'2021-12-08 18:21:50','nosto',200,4),(152,'2021-12-08 18:21:52','nosto',200,4),(153,'2021-12-08 18:21:52','nosto',200,4),(154,'2021-12-08 18:21:56','pano',200,4),(155,'2021-12-08 18:21:56','pano',200,4),(156,'2021-12-08 18:21:57','pano',200,4),(157,'2021-12-08 18:21:57','pano',200,4),(158,'2021-12-09 13:45:48','pano',1,1),(159,'2021-12-09 14:07:05','nosto',20,3);
/*!40000 ALTER TABLE `tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'pankkiautomaatti'
--
/*!50003 DROP PROCEDURE IF EXISTS `LisaaTapahtumia` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `LisaaTapahtumia`(IN KorttiID INT, IN offsetID INT, IN Tila1 INT )
BEGIN
select idTilitapahtumat, aika, Tapahtuma, Maara from tilitapahtumat JOIN tili ON tilitapahtumat.Tili_idTili=tili.idTili join kortti on tili.idTili=kortti.tili_idTili where idKortti=KorttiID AND Tila=Tila1 order by idTilitapahtumat desc limit 10 offset offsetID ;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `nostarahaa` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `nostarahaa`(IN KorttiID INT, IN summa INT, IN Tila1 INT)
BEGIN
  DECLARE test1, test2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE tili JOIN Kortti ON tili.idTili=kortti.tili_idTili SET saldo=saldo-summa WHERE idKortti=KorttiID AND saldo>=summa  AND Tila = Tila1 ;
  SET test1=ROW_COUNT();
   select idTili into test2 from Tili join KORTTI ON tili.idtili=kortti.tili_idtili WHERE idKortti = KorttiID AND Tila = Tila1 ;
    IF (test1 > 0) THEN
      COMMIT;
      INSERT INTO tilitapahtumat(aika,tapahtuma,maara,tili_idtili) VALUES(NOW(),'nosto',summa, test2);
    ELSE
      ROLLBACK;
  END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `panerahaa` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `panerahaa`(IN KorttiID INT, IN summa INT, IN Tila1 INT )
BEGIN
  DECLARE test1, test2, luottoRaja1, saldo1 INT DEFAULT 0;
  START TRANSACTION;
   select Saldo into saldo1 from tili JOIN Kortti ON tili.idTili=kortti.tili_idTili WHERE idKortti=KorttiID AND Tila=Tila1;
  select luottoraja into luottoraja1 from tili JOIN Kortti ON tili.idTili=kortti.tili_idTili WHERE idKortti=KorttiID AND Tila=Tila1;
  IF (summa + saldo1 > luottoraja1 AND Tila1 = 0) THEN
  ROLLBACK;
 ELSE
  UPDATE tili JOIN Kortti ON tili.idTili=kortti.tili_idTili SET saldo=saldo+summa WHERE idKortti=KorttiID AND Tila=Tila1;
  SET test1=ROW_COUNT();
   select idTili into test2 from Tili join KORTTI ON tili.idtili=kortti.tili_idtili WHERE idKortti = KorttiID AND Tila=Tila1;
    IF (test1 > 0) THEN
      COMMIT;
      INSERT INTO tilitapahtumat(aika,tapahtuma,maara,tili_idtili) VALUES(NOW(),'pano',summa, test2);
    ELSE
      ROLLBACK;
  END IF;
  END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-09 14:10:40
