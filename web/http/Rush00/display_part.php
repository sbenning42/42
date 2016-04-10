<?PHP
function	display_part()
{
	$product_list = product_list();
	if (sizeof($product_list) > 4)
		$nb = 8;
	else
		$nb = sizeof($product_list);
	foreach ($product_list as $product)
	{
		echo '<div class="part_border">';
		echo '<img class="part" src="'.$product['img'].'" />';
		echo '</div>';
		if (--$nb === 0)
			break;
	}
}
?>
