<?PHP
$category_list = category_list();
echo "<h2 id=category>Categories</h2><br>";
echo '<form action="display_category_content.php" method=post>';
foreach ($category_list as $category)
	echo '<br><input class=category name=category type="submit" value="'.$category['id'].'"><br>';
echo '</form>';
?>
