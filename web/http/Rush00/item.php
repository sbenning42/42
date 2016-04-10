<?PHP
session_start();
include("navbar.php");
function display_panier()
{
	echo '<h3>TOTAL</h3>';
	foreach ($_SESSION['panier']['content'] as $item)
	{
		$product = product_get($item);
		echo '<div class="part_border">';
		echo '<p>Product: '.$product["id"].' Price: '.$product["price"].'</p>';
		$total += $product['price'];
		echo '</div>';
		echo '<br>';
	}
	echo "<hr>";
	echo "Total: ".$total." Euros";
	if (!$_SESSION['loggued_on_user'])
		echo ' Please <a href="index.php">login</a> to validate';
	else
	{
		echo '<form action="validate.php" method=post>';
		echo '<input type=submit value="validate" name="validate">';
		echo '</form>';
	}
}
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
			.part
			{
				width: 80%;
			}
			.part_border
			{
				display: inline-block;
				text-align: center;
			}
		</style>
	</head>
	<body>
		<div id=intern_body>
		<?PHP if ($_SESSION['loggued_on_user']) echo '<h2>Bienvenue '.$_SESSION['loggued_on_user'].'</h2>'; 
		display_panier(); ?>
		</div>
	</body>

</html>
