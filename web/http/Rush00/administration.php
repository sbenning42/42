<?PHP
session_start();
include("navbar.php");
if (is_admin($_SESSION['loggued_on_user']) !== 'admin')
{
	echo '<h4 color=red>HOo You Touch My URLala... My Ding Ding Dong</h4>';
	exit;
}
if ($_POST['new_category'])
	category_add_entry($_POST['new_category']);
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
			<a href="add_category.php">Add Category</a><br>
			<a href="">Add Product</a><br>
			<a href="">Remove Category</a><br>
			<a href="">Remove Product</a><br>
			<a href="">Modify Category</a><br>
			<a href="">Modify Product</a><br>
			<a href="">Add User</a><br>
			<a href="">Remove User</a><br>
			<a href="">Modify User</a>
		</div>
	</body>
</html>
