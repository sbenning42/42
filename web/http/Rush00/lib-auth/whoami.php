<?PHP
session_start();
if ($_SESSION['loggued_on_user'] == NULL OR $_SESSION['loggued_on_user'] === "")
	echo "ERROR".PHP_EOL;
else
	echo $_SESSION['loggued_on_user'].PHP_EOL;
?>
