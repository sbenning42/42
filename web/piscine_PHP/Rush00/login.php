<?php
	include ("auth.php");
	session_start();

	$_SESSION['loggued_on_user'] = "";
	if (auth($_POST['login'], $_POST['passwd']) === TRUE)
		$_SESSION['loggued_on_user'] = $_POST['login'];
	header("Location: index.php");
?>
