<?PHP
	session_start();
if ($_GET['login'] == NULL)
	$S_SESSION['login'] = "";
if ($_GET['passwd'] == NULL)
	$S_SESSION['passwd'] = "";
if ($_GET['submit'] == NULL)
	$S_SESSION['submit'] = "";
?>
<html>
	<head>
	</head>
	<body>
<?PHP
if ($_GET['submit'] == "OK")
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
?>
		<form action="index.php" method="get">
			Identifiant: <input type=text name=login placeholder="login" value="<?PHP echo $_SESSION['login']; ?>"><br>
			Mot de passe: <input type=text name=passwd placeholder="*************" value="<?PHP echo $_SESSION['passwd']; ?>"><br>
			<input type=submit name=submit value="OK">
		</form>
	</body>
</html>
