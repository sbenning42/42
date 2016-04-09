<?PHP
include("display_category.php");
session_start();
if (!$_SESSION['panier'])
	$_SESSION['panier'] = 0;
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
				width: 15%;
				min-width: 200px;
				height: 80%;
				background-color: lightgrey;
				text-align: center;
			}
			#menu input
			{
				width: 60%;
				margin-left: 20%;
				margin-right: 20%;
			}
			#category_list
			{
				border-color: black;
			}
			.category
			{
			}
		</style>
	</head>
	<body>
		<div id="navbar">
			<img src="img/navbar.jpg" alt="navbar" />
			<a href="item.php"><img id="item" src="img/item.jpg" alt="[]" /></a>
			<span id=item_number><?PHP echo $_SESSION['panier']; ?></span>
		</div>
		<div id="menu">
			<form id="login" action="login.php" method="post">
				Identifiant: <input type=text name=login placeholder="login" value=""><br>
				Mot de passe: <input type=password name=passwd placeholder="*************" value=""><br>
				<input type=submit name=submit value="OK"><br>
			</form>
			<div id=category_list>
				<?PHP display_category();?>
			</div>
		</div>
	</body>
</html>
