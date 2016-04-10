<?PHP
include("display_category.php");
if (!$_SESSION['panier'])
	$_SESSION['panier'] = array('size' => 0, 'content' => array());
?>
<html>
	<head>
		<style>
			body
			{
				margin: 0;
				padding: 0;
				width: 100%;
				height: 100%;
				min-height: 700px;
			}
			#navbar
			{
				position: relative;
				z-index: 99;
				width: 100%;
				min-width: 1400px;
				height: 30%;
				background-color: grey;
				text-align: center;
			}
			#navbar img
			{
				height: 100%;
				width: 70%;
				border-radius: 25px;
			}
			#item
			{
				position: absolute;
				top: 35%;
				right: 2.5%;
				height: 35% !important;
				width: 10% !important;
			}
			#item_number
			{
				position: absolute !important;
				top: 40% !important;
				right: 10% !important;
				color: red;	
				font-size: 400% !important;
			}

			#menu
			{
				display: inline-block;
				width: 15%;
				min-width: 200px;
				height: 100%;
				background-color: lightgrey;
				text-align: center;
			}
			#menu input
			{
				width: 60%;
				margin-left: 20%;
				margin-right: 20%;
				overflow: hidden;
			}
			#category
			{
				margin-top: 10%;
				margin-bottom: 0;
			}
		</style>
	</head>
	<body>
		<div id="navbar">
			<img src="img/navbar.jpg" alt="navbar" />
			<a href="item.php"><img id="item" src="img/item.jpg" alt="[]" /></a>
			<span id=item_number><?PHP echo $_SESSION['panier']['size']; ?></span>
		</div>
		<div id="menu">
			<form action="create.php" method="post">
				<h2>Singn In</h2>
				Identifiant: <input type=text name=login placeholder="login" value=""><br>
				Mot de passe: <input type=password name=passwd placeholder="*************" value=""><br>
				<input type=submit name=submit value="OK">
			<?PHP if ($_SESSION['cre_error'] === 1) echo "<font color=red>ERROR<br>Please choose another login</font>";?>
			</form>
			<form action="login.php" method="post">
				<h2>Login</h2>
				Identifiant: <input type=text name=login placeholder="login" value=""><br>
				Mot de passe: <input type=password name=passwd placeholder="*************" value=""><br>
				<input type=submit name=submit value="OK"><br>
			<?PHP if ($_SESSION['log_error'] === 1) echo "<font color=red>ERROR<br>Invalid login</font>";?>
			</form>
			<form action="logout.php" method="post">
				<input type=submit name=Logout value="Logout"><br>
			</form>
			<form action="index.php">
				<h2>Home</h2>
				<input type=submit name=Home value="Go!"><br>
			</form>
<?PHP
include("user.php");
if (is_admin($_SESSION['loggued_on_user']) === 'admin')
{
			echo '<form id="login" action="administration.php">';
			echo '<h2>Administration</h2>';
			echo '<input type=submit name=Administration value="Administration"><br>';
			echo '</form>';
}
?>
			<div id=category_list>
				<?PHP display_category();?>
			</div>
		</div>
	</body>
</html>
