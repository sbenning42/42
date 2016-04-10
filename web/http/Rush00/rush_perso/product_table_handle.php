<?PHP

function	table_dump($i)
{
	if (file_exists("resources/category"))
	{
		$data = unserialize(file_get_contents("resources/category"));
		file_put_contents("log.".$i , print_r($data, TRUE));
	}
	if (file_exists("resources/product"))
	{
		$data = unserialize(file_get_contents("resources/product"));
		file_put_contents("log.".$i , print_r($data, TRUE), FILE_APPEND);
	}
	if (file_exists("resources/join"))
	{
		$data = unserialize(file_get_contents("resources/join"));
		file_put_contents("log.".$i , print_r($data, TRUE), FILE_APPEND);
	}
}

function	serialize_put_content($path, $data)
{
	$fd = fopen($path, "w");
	flock($fd, LOCK_EX);
	file_put_contents($path, serialize($data));
	flock($fd, LOCK_UN);
	fclose($fd);
 }

function	unserialize_get_content($path)
{
	if (file_exists($path))
	{
		$fd = fopen($path, "r");
		flock($fd, LOCK_SH);
		$data = unserialize(file_get_contents($path));
		flock($fd, LOCK_UN);
		fclose($fd);
		return $data;
	}
	return NULL;
}

function	product_add_entry($entry, $category_list, $img_src, $price)
{
	if (!file_exists("resources") OR empty($category_list) OR !file_exists("resources/category"))
		return FALSE;
	if (file_exists("resources/product"))
		$table_product = unserialize_get_content("resources/product");
	if ($table_product[$entry]['exist'] === 1)
		return FALSE;
	$table_category = unserialize_get_content("resources/category");
	if (file_exists("resources/join"))
		$table_join = unserialize_get_content("resources/join");
	foreach ($category_list as $category)
	{
		if ($table_category[$category]['exist'] !== 1)
			return FALSE;
	}
	foreach ($category_list as $category)
		$table_join[$category."<:>".$entry] = 1;
	$table_product[$entry]['id'] = $entry;
	$table_product[$entry]['exist'] = 1;
	$table_product[$entry]['nb_category'] = sizeof($category_list);
	$table_product[$entry]['img'] = $img_src;
	$table_product[$entry]['price'] = $price;
	serialize_put_content("resources/join", $table_join);
	serialize_put_content("resources/product", $table_product);
}

function	category_add_entry($entry)
{
	if (!file_exists("resources"))
		mkdir("resources", 0777);
	else
	{
		if (file_exists("resources/category"))
			$table_category = unserialize_get_content("resources/category");
	}
	if ($table_category[$entry]['exist'] === 1)
		return (FALSE);
	$table_category[$entry]['id'] = $entry;
	$table_category[$entry]['exist'] = 1;
	serialize_put_content("resources/category", $table_category);
}

function	product_rem_entry($entry)
{
	if (!file_exists("resources/product") || !file_exists("resources/join"))
		return FALSE;
	$table_product = unserialize_get_content("resources/product");
	if ($table_product[$entry]['exist'] !== 1)
		return FALSE;
	unset($table_product[$entry]);
	$table_join = unserialize_get_content("resources/join");
	$tmp = $table_join;
	foreach ($tmp as $key => $join)
	{
		if (preg_match("/^.*<:>$entry$/", $key, $match) === 1)
			unset($table_join[$match[0]]);
	}
	serialize_put_content("resources/product", $table_product);
	serialize_put_content("resources/join", $table_join);
}

function	category_rem_entry($entry)
{
	if (!file_exists("resources/category"))
		return FALSE;
	$table_category = unserialize_get_content("resources/category");
	if ($table_category[$entry]['exist'] !== 1)
		return FALSE;
	unset($table_category[$entry]);
	serialize_put_content("resources/category", $table_category);
	if (!file_exists("resources/join") OR !file_exists("resources/product"))
		return ;
	$table_join = unserialize_get_content("resources/join");
	$table_product = unserialize_get_content("resources/product");
	$tmp = $table_join;
	foreach ($tmp as $key => $join)
	{
		if (preg_match("/^$entry<:>(.*)$/", $key, $match) === 1)
		{
			if (--$table_product[$match[1]]['nb_category'] === 0)
				unset($table_product[$match[1]]);
			unset($table_join[$match[0]]);
		}
	}
	serialize_put_content("resources/join", $table_join);
	serialize_put_content("resources/product", $table_product);
}

function	category_get_product($category)
{
	if (!file_exists("resources/product") OR !file_exists("resources/join") OR !file_exists("resources/category"))
		return FALSE;
	$table_category = unserialize_get_content("resources/category");
	if ($table_category[$category]['exist'] !== 1)
		return FALSE;
	$table_join = unserialize_get_content("resources/join");
	$table_product = unserialize_get_content("resources/product");
	foreach ($table_join as $key => $join)
	{
		if (preg_match("/^$category<:>(.*)$/", $key, $match) === 1)
			$product[$match[1]] = $table_product[$match[1]];
	}
	return $product;
}

function	product_get_category($product)
{
	if (!file_exists("resources/product") OR !file_exists("resources/join") OR !file_exists("resources/category"))
		return FALSE;
	$table_product = unserialize_get_content("resources/product");
	if ($table_product[$product]['exist'] !== 1)
		return FALSE;
	$table_join = unserialize_get_content("resources/join");
	$table_category = unserialize_get_content("resources/category");
	foreach ($table_join as $key => $join)
	{
		if (preg_match("/^(.*)<:>$product$/", $key, $match) === 1)
			$category[$match[1]] = $table_category[$match[1]];
	}
	return $category;
}

function	product_list()
{
	return unserialize_get_content("resources/product");
}

function	category_list()
{
	return unserialize_get_content("resources/category");
}

function	product_get($product)
{
	if (!file_exists("resources/product"))
		return FALSE;
	$table_product = unserialize_get_content("resources/product");
	if ($table_product[$product]['exist'] !== 1)
		return FALSE;
	return $table_product[$product];
}

function	category_get($category)
{
	if (!file_exists("resources/category"))
		return FALSE;
	$table_category = unserialize_get_content("resources/category");
	if ($table_category[$category]['exist'] !== 1)
		return FALSE;
	return $table_category[$category];
}

function	product_modif($product)
{
	if (!file_exists("resources/product"))
		return FALSE;
	$table_product = unserialize_get_content("resources/product");
	if ($table_product[$product['id']]['exist'] !== 1)
		return FALSE;
	$table_product[$product['id']] = $product;
	serialize_put_content("resources/product", $table_product);
}
 
function	category_modif($category)
{
	if (!file_exists("resources/category"))
		return FALSE;
	$table_category = unserialize_get_content("resources/category");
	if ($table_category[$category['id']]['exist'] !== 1)
		return FALSE;
	$table_category[$category['id']] = $category;
	serialize_put_content("resources/category", $table_category);
}

function	product_id_modif($old_id, $new_id)
{
	if (!file_exists("resources/product") OR !file_exists("resources/join"))
		return FALSE;
	if (($product = product_get($old_id)) === FALSE OR product_get($new_id) != FALSE)
		return FALSE;
	$table_join = unserialize_get_content("resources/join");
	foreach ($table_join as $key => $join)
	{
		if (preg_match("/^(.*)<:>$old_id$/", $key, $match) === 1)
			$category_list[] = $match[1];
	}
	product_rem_entry($old_id);
	product_add_entry($new_id, $category_list, $product['img']);
}

function	category_id_modif($old_id, $new_id)
{
	if (!file_exists("resources/category") OR !file_exists("resources/join"))
		return FALSE;
	$table_category = unserialize_get_content("resources/category");
	if ($table_category[$old_id]['exist'] !== 1 OR $table_category[$new_id]['exist'] === 1)
		return FALSE;
	$table_category[$new_id] = $table_category[$old_id];
	$table_category[$new_id]['id'] = $new_id;
	unset($table_category[$old_id]);
	$table_join = unserialize_get_content("resources/join");
	$tmp = $table_join;
	foreach ($tmp as $key => $join)
	{
		if (preg_match("/^".$old_id."<:>(.*)$/", $key, $match) === 1)
		{
			$table_join[$new_id."<:>".$match[1]] = $table_join[$key];
		 	unset($table_join[$key]);
		 }
	}
	serialize_put_content("resources/category", $table_category);
	serialize_put_content("resources/join", $table_join);
 }

?>
