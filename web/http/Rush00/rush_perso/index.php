<?PHP
include("product_table_handle.php");
session_start();
if (!isset($_SESSION['first_visit']))
{
	$_SESSION['first_visit'] = 1;
	$_SESSION['legit_route'] = FALSE;
	$_SESSION['comefrom'] = 'index.php';
	$_SESSION['logged'] = FALSE;
	$_SESSION['admin'] = TRUE;
	$_SESSION['user'] = "";
	$_SESSION['cart'] = array('size' => 0, 'content' => array());
}
include('navbar.php');
?>
	</div>
</body>
</html>
