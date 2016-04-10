<?php
	include ("auth.php");
	session_start();

	$_SESSION['log_error'] = 0;
	$_SESSION['loggued_on_user'] = "";
	if ($_POST['login'] == "" OR $_POST['passwd'] == "")
	{
		header("Location: index.php");
		exit;
	}
	if (auth($_POST['login'], $_POST['passwd']) === TRUE)
		$_SESSION['loggued_on_user'] = $_POST['login'];
	else
		$_SESSION['log_error'] = 1;
	header("Location: index.php");
?>
