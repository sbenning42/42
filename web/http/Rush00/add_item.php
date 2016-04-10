<?PHP
session_start();
$_SESSION['panier']['size'] += 1;
foreach ($_POST as $item)
{
	preg_match("/add (.*)$/", $item, $match);
	$_SESSION['panier']['content'][] = $match[1];
}
header("Location: display_category_content.php");
?>
