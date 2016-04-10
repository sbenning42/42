<?PHP
session_start();
?>
<html>
<head>
	<meta charset=utf-8>
	<link rel=stylesheet type=text/css href=index.css>
	<title>Longboardshop 42</title>
</head>
<body>
	<div id="navbar">
		<img id="user" src="img/<?PHP if ($_SESSION['admin'] === TRUE) {echo 'admin';} else {echo 'user';} ?>.png"/>
		<img id="ban" src="img/navbar.jpg"/>
		<img id="cart" src="img/cart.png"/>
		<font id="item"><?PHP echo $_SESSION['cart']['size'];?></font>
	</div>
	<div id="menu">
		<?PHP include("display_category_list.php");?>
	</div>
	<div id="display_body">
