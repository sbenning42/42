<?PHP

session_start();
include("");
if ($_SESSION['loggued_on_user'] !== 'admin')
{
	echo '<h4 style="color=red;">DON\'T HAVE PERMISSION!!!</h4>';
	exit;
}
include("navbar.php");
?>

<html>
	<head>
		<style>
			#intern_body
			{
				display: inline-block;
				position: absolute;
				text-align: center;
				min-width: 1200px;
				width: 85%;
				height: 80%;
			}
		</style>
	</head>
	<body>
		<div id="intern_body">
		<?PHP if ($_SESSION['loggued_on_user']) echo '<h2>Bienvenue '.$_SESSION['loggued_on_user'].'</h2>'; ?>
			<form action="administration.php" method="post">
				<h2>Login</h2>
				Category: <input type=text name=new_category placeholder="New Category Name" value=""><br>
				<input type=submit name=submit value="OK"><br>
			<?PHP if ($_SESSION['log_error'] === 1) echo "<font color=red>ERROR<br>Invalid login</font>";?>
			</form>

		</div>
	</body>
</html>
