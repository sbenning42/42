
<?PHP
include("product_table_handle.php");
function	display_category()
{
	$category_list = category_list();
	echo '<form action="display_category_content.php">';
	foreach ($category_list as $category)
	{
		echo '<br><input class=category type="submit" value="'.$category['id'].'"><br>';
	}
	echo '</form>';
}
?>
