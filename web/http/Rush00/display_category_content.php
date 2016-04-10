<?PHP
session_start();
include("navbar.php");
function display()
{
	if ($_POST['category'])
	{
		$_SESSION['category'] = $_POST['category'];
	}
	if (!($product_list = category_get_product($_SESSION['category'])))
	{
		echo "No Product in this category";
		exit;
	}
	foreach ($product_list as $product)
	{
		echo '<div class="part_border">';
		echo '<img class="part" src="'.$product['img'].'" /><br>';
		echo '<p>PRICE: '.$product['price'].'</p>';
		echo '<form action="add_item.php" method=post>';
		echo '<input type=submit value="add '.$product['id'].'" name="'."item".'">';
		echo '</form>';
		echo '</div>';
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
				width: 25%;
			}
		</style>
	</head>
	<body>
		<div id=intern_body>
		<?PHP if ($_SESSION['loggued_on_user']) echo '<h2>Bienvenue '.$_SESSION['loggued_on_user'].'</h2>';
		display(); ?>
		</div>
	</body>

</html>
