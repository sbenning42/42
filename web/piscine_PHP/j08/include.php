<?php
session_start();
require_once ("./class/Board.class.php");
require_once ("./class/Player.class.php");
require_once "./class/Weapon.class.php";
require_once "./class/Ship.class.php";
require_once "./class/HeavyMachineGun.class.php";
require_once "./class/ImperialDestroyer.class.php";
require_once "./class/ImperialCruiser.class.php";
require_once ("./trait/Moove.trait.php");


$mysqli = new mysqli("37.187.120.240", "rush01", "rush01", "rush01");
if ($mysqli->connect_errno) {
      echo "Failed to connect to MySQL: " . $mysqli->connect_error;
}
?>
