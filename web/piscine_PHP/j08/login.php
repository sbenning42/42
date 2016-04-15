<?php
require_once("./include.php");

if(isset($_POST['submit']) && $_POST['submit'] == "Inscription")
{
      if (isset($_POST['login']) && isset($_POST['passwd']))
      {
            $sqlLogin = "SELECT * FROM  `player` WHERE  `login` LIKE  '".$_POST['login']."'";
            $result = $mysqli->query($sqlLogin);
            $obj = $result->fetch_object();
            if (empty($obj))
            {
                  $sqlPlayerInsert = "INSERT INTO  `player` (
                  `id` ,
                  `login` ,
                  `passwd` ,
                  `etat`
                  )
                  VALUES (
                  NULL ,  '".$_POST['login']."',  '".hash("whirlpool",$_POST['passwd'])."',  '0'
                  );";
                  $mysqli->query($sqlPlayerInsert);
                  $_SESSION['login'] = $_POST['login'];
                  $_SESSION['id'] = $mysqli->insert_id;
            }
      }
}

if(isset($_POST['submit']) && $_POST['submit'] == "Login")
{
      if (isset($_POST['login']) && isset($_POST['passwd']))
      {
            $sqlLogin = "SELECT * FROM  `player` WHERE  `login` LIKE  '".$_POST['login']."'";
            $result = $mysqli->query($sqlLogin);
            $obj = $result->fetch_object();
            if (hash("whirlpool",$_POST['passwd']) == $obj->passwd)
            {
                  $_SESSION['login'] = $obj->login;
                  $_SESSION['id'] = $obj->id;
            }
      }
}
?>

<!DOCTYPE html>
<html class="bgimg stars">
  <head>
    <title>Title of the document</title>
    <link rel="stylesheet" type="text/css" href="./resources/style.css">
    <link rel="stylesheet" type="text/css" href="./resources/sw.css">
    <link rel="stylesheet" type="text/css" href="./resources/stars.css">
    <link rel="stylesheet" type="text/css" href="./map.css.php">
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.2/jquery.min.js"></script>
  </head>
      <body>

<div class="stars"></div>
<div class="twinkling"></div>
<div class="clouds"></div><!---->
<?php
if (!isset($_SESSION['id']))
{
?>
      <div class="login">
            Se connecter : <br />
            <form action="login.php" method="POST">
                  <input type="text" name="login" value="">
                  <input type="password" name="passwd" value="">
                  <input type="submit" name="submit" value="Login">
            </form>
            <br />
            Inscription : <br />
            <form action="login.php" method="POST">
                  <input type="text" name="login" value="">
                  <input type="password" name="passwd" value="">
                  <input type="submit" name="submit" value="Inscription">
            </form>
      </div>
<?php
}
else
{
    ?>
<div class="login play">
  <a href="./join.php" style="inherit"> Jouer a Warhammer 40K Annihilation</a>
</div>
    <?php
}
include("template/sw.php");
?>


            <script src="./resources/ajax.js"></script>
      </body>
</html>
