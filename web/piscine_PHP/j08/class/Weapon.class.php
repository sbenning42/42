<?PHP

abstract class				Weapon
{
	public static			$verbose = FALSE;
	protected				$_name;
	protected				$_chargeInit;
	protected				$_charge;
	protected				$_shootAera;
	protected				$_shootType;
	protected				$_format = "%s( type: %s, name: %s, charge: %d,  Near: %d, Middle: %d, Far: %d )";

	abstract function		getImpactAera($impactPos);
	abstract function		who();

	public function			__construct($sootType)
	{
		if (self::$verbose === TRUE)
			print($this . " constructed." . PHP_EOL);
		$this->reset();;
	}

	public function			__destruct()
	{
		if (self::$verbose === TRUE)
			print($this . " destructed." . PHP_EOL);
	}

	public function			__toString()
	{
		return sprintf($this->_format, static::who(), $this->shootType, $this->_name, $this->_charge, $this->_shootAera['near'], $this->_shootAera['middle'], $this->_shootAera['far']);
	}

	public static function	doc()
	{
		if (file_exists('Weapon.doc.txt'))
			return file_get_contents('Weapon.doc.txt');
	}

	public function			getName()
	{
		return $this->_name;
	}

	public function			getChargeStrict()
	{
		return $this->_charge;
	}

	public function			getShootAera()
	{
		return $this->_shootAera;
	}

	public function			give_chargePP($PP)
	{
		$this->_chargePP += $PP;
	}

	public function			getCharge()
	{
		return $this->_charge;
	}

	public function			reset()
	{
		$this->_charge = $this->_chargeInit;
	}

	public function			getShootableAera($position, $size)
	{
		$offl = ($size['l'] - 1) / 2;
		$offL = ($size['L'] - 1) / 2;
		$offShipX = (($position['dir'] === 'N' OR $position['dir'] === 'S') ? $offl : $offL);
		$offShipY = (($position['dir'] === 'N' OR $position['dir'] === 'S') ? $offL : $offl);

		$offNearX = $offShipX + $this->_shootAera['near'];
		$offNearY = $offShipY + $this->_shootAera['near'];

		$offMiddleX = $offShipX + $this->_shootAera['middle'];
		$offMiddleY = $offShipY + $this->_shootAera['middle'];

		$offFarX = $offShipX + $this->_shootAera['far'];
		$offFarY = $offShipY + $this->_shootAera['far'];

		$x_cp = $position['x'] - ($offFarX + 1);
		$y = $position['y'] - ($offFarY + 1);
		$xMax = $position['x'] + $offFarX;
		$yMax = $position['y'] + $offFarY;

		while (++$y <= $yMax)
		{
			if ($y < 0)
				continue ;
			$x = $x_cp;
			while (++$x <= $xMax)
			{
				if ($x < 0)
					continue ;
				if (($x > ($position['x'] + $offMiddleX) OR $y > ($position['y'] + $offMiddleY)) OR ($x < ($position['x'] - $offMiddleX) OR $y < (($position['y'] - $offMiddleY))))
					$dist = 'far';
				else if (($x > ($position['x'] + $offNearX) OR $y > ($position['y'] + $offNearY)) OR ($x < ($position['x'] - $offNearX) OR $y < (($position['y'] - $offNearY))))
					$dist = 'middle';
				else if (($x > ($position['x'] + $offShipX) OR $y > ($position['y'] + $offShipY)) OR ($x < ($position['x'] - $offShipX) OR $y < (($position['y'] - $offShipY))))
					$dist = 'near';
				else
					$dist = 'ship';
				$aera[] = array('x' => $x, 'y' => $y, 'dist' => $dist);
			}
		}
		return $aera;
	}
}

?>
