SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

CREATE SCHEMA IF NOT EXISTS `Players` ;
USE `Players` ;

-- -----------------------------------------------------
-- Table `Players`.`Player1`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Players`.`Player1` (
    `idPlayerData` INT NOT NULL,
    `Name` VARCHAR(45) NOT NULL DEFAULT 'Player',
    `Hacking` FLOAT NOT NULL DEFAULT 0.0,
    `Encryption` FLOAT NOT NULL DEFAULT 0.0,
    `Decryption` FLOAT NOT NULL DEFAULT 0.0,
    `Intelligence` FLOAT NOT NULL DEFAULT 0.0,
    `GatherIntel` FLOAT NOT NULL DEFAULT 0.0,
    `Timing` FLOAT NOT NULL DEFAULT 0.0,
    `Speed` FLOAT NOT NULL DEFAULT 0.0,
    `Prediction` FLOAT NOT NULL DEFAULT 0.0,
    `Hiding` FLOAT NOT NULL DEFAULT 0.0,
    PRIMARY KEY (`idPlayerData`)
)  ENGINE=InnoDB;


-- -----------------------------------------------------
-- Table `Players`.`Jacob`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Players`.`Jacob` (
    `idPlayerData` INT NOT NULL,
    `Name` VARCHAR(45) NOT NULL DEFAULT 'Jacob',
    `Hacking` FLOAT NOT NULL DEFAULT 0.0,
    `Encryption` FLOAT NOT NULL DEFAULT 0.0,
    `Decryption` FLOAT NOT NULL DEFAULT 0.0,
    `Intelligence` FLOAT NOT NULL DEFAULT 0.0,
    `GatherIntel` FLOAT NOT NULL DEFAULT 0.0,
    `Timing` FLOAT NOT NULL DEFAULT 0.0,
    `Speed` FLOAT NOT NULL DEFAULT 0.0,
    `Prediction` FLOAT NOT NULL DEFAULT 0.0,
    `Hiding` FLOAT NOT NULL DEFAULT 0.0,
    PRIMARY KEY (`idPlayerData`)
)  ENGINE=InnoDB;


-- -----------------------------------------------------
-- Table `Players`.`Player2`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Players`.`Player2` (
    `idPlayerData` INT NOT NULL,
    `Name` VARCHAR(45) NOT NULL DEFAULT 'Player',
    `Hacking` FLOAT NOT NULL DEFAULT 0.0,
    `Encryption` FLOAT NOT NULL DEFAULT 0.0,
    `Decryption` FLOAT NOT NULL DEFAULT 0.0,
    `Intelligence` FLOAT NOT NULL DEFAULT 0.0,
    `GatherIntel` FLOAT NOT NULL DEFAULT 0.0,
    `Timing` FLOAT NOT NULL DEFAULT 0.0,
    `Speed` FLOAT NOT NULL DEFAULT 0.0,
    `Prediction` FLOAT NOT NULL DEFAULT 0.0,
    `Hiding` FLOAT NOT NULL DEFAULT 0.0,
    PRIMARY KEY (`idPlayerData`)
)  ENGINE=InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
