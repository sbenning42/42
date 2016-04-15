<?PHP

abstract class				Ship
{
	static protected		$_idCount = 0;
	protected				$_id;
	protected				$_owner;			//	Player 1 || 2
	protected				$_name;				//	Badass Name
	protected				$_spriteSrc;		//	Sprite Path
	protected				$_actived;			//	Boolean TRUE is ever activated this tour
	protected				$_position;			//	array('x' => Xcenter, 'y' => Ycenter, 'dir' => N || S || W || E)
	protected				$_size;				//	array('x' => largeur, 'y' => Longueur)
	protected				$_maneuvreInit;		//	Carac
	protected				$_speedInit;		//	Carac
	protected				$_PpInit;			//	Carac
	protected				$_PvInit;			//	Carac
	protected				$_PsInit;
	protected				$_Pv;			//	Current Carac PV Value
	protected				$_Pp;			//	Current Carac PP Value
	protected				$_Ps;				//	Current Carac Shield Value (+PP)
	protected				$_moved;		//	Carac
	protected				$_maneuvre;		//	Carac
	protected				$_speed;			//	Current Carac Speed Value (+PP)
	protected				$_weapons;			//	array(new Weapon, new Weapon ...)
	protected				$_lastState;			//	Last mobility state
	protected				$_state;			//	Current mobility state
	protected				$_format = "Ship( type: %s, name: %s, sprite: %s, size: %s, center: %s, direction: %s, PV: %d, PP: %d, speed: %d, maneuvrability: %d, weapons[%d]: %s)";
	static public			$verbose = FALSE;

	abstract function		fire($target);
	abstract function		who();

	protected function		resetPP()
	{
		$this->_Pp = $this->_PpInit;
		$this->_speed = $this->_speedInit;
		$this->_Ps = $this->_PsInit;
		foreach ($this->_weapons as $weapon)
			$weapon->reset();
	}

	public function			__construct($owner)
	{
		if (self::$verbose === TRUE)
			print($this . " constructed." . PHP_EOL);
		self::$_idCount += 1;
		$this->_id = self::$_idCount;
		$this->_owner = $owner;
		$this->_lastState = "motionless";
		$this->_state = "motionless";
		$this->_Pp = $this->_PpInit;
		$this->_Pv = $this->_PvInit;
		$this->_Ps = $this->_PsInit;
		$this->_speed = $this->_speedInit;
		$this->_maneuvre = $this->_maneuvreInit;
		$this->_moved = 0;
		if ($owner === 1)
			$this->_position['dir'] = 'N';
		else
			$this->_position['dir'] = 'S';
		print("dir = " . $this->_position['dir'] . PHP_EOL);
		$this->reset();
	}

	public function			__destruct()
	{
		if (self::$verbose === TRUE)
			print($this . " destructed." . PHP_EOL);
	}

	public function			__toString()
	{
		$i = sizeof($this->_weapons);
		foreach ($this->_weapons as $weapon)
		{
			$str .= $weapon->getName();
			if (--$i !== 0)
				$str .= ", ";
			else
				$str .= " ";
		}
		return sprintf($this->_format, static::who(), $this->_name, $this->_spriteSrc, $this->_size['L'] . "x" . $this->_size['l'], $this->center['L'] . "x" . $this->center['l'], $this->dir, $this->_PvMax, $this->_PpMax, $this->_speed, $this->_maneuvrability, sizeof($this->_weapons), $str);
	}

	public static function	doc()
	{
		if (file_exists('Ship.doc.txt'))
			return file_get_contents('Ship.doc.txt');
	}

	public function			getId()
	{
		return $this->_id;
	}

	public function			getOwner()
	{
		return $this->_owner;
	}

	public function			getName()
	{
		return $this->_name;
	}

	public function			getSprite()
	{
		return $this->_spriteSrc;
	}

	public function			getSize()
	{
		return $this->_size;
	}

	public function			getPv()
	{
		return $this->_Pv;
	}

	public function			getPp()
	{
		return $this->_Pp;
	}

	public function			getPs()
	{
		return $this->_Ps;
	}

	public function			getSpeed()
	{
		return $this->_speed;
	}

	public function			getManeuvre()
	{
		return $this->_maneuvre;
	}

	public function			getWeapons()
	{
		return $this->_weapons;
	}

	public function			getActivated()
	{
		return $this->_activated;
	}

	public function			getPosition()
	{
		return $this->_position;
	}

	public function			setPosition($position)
	{
		if (isset($position['dir']))
			$this->_position['dir'] = $position['dir'];
		$this->_position['x'] = $position['x'];
		$this->_position['y'] = $position['y'];
	}

	public function			active()
	{
		$this->_actived = TRUE;
	}

	public function			repare()
	{
		if ($this->_Pp < 1)
			return FALSE;
		if ($this->_Pv < $this->_PvInit)	// D6
			$this->_Pv += 1;
		$this->_Pp -= 1;
	}

	public function			givePPshield($PP)
	{
		if ($PP > $this->_Pp)
			return FALSE;
		$this->_Pp -= $PP;
		$this->_Ps += $PP;
	}

	public function			givePPspeed($PP)
	{
		if ($PP > $this->_Pp)
			return FALSE;
		$this->_Pp -= $PP;
		$this->_speed += $PP;				//	D6
	}

	public function			getSpace($physical = FALSE)
	{
		$offl = ($this->_size['l'] - 1) / 2;
		$offL = ($this->_size['L'] - 1) / 2;
		if ($physical !== TRUE)
		{
			$offl += $this->_weapons[0]->getShootAera()['near'];
			$offL += $this->_weapons[0]->getShootAera()['near'];
		}
		$offX = (($this->_position['dir'] === 'N' OR $this->_position['dir'] === 'S') ? $offl : $offL);
		$offY = (($this->_position['dir'] === 'N' OR $this->_position['dir'] === 'S') ? $offL : $offl);
		$x = $this->_position['x'] - $offX;
		$y = $this->_position['y'] - $offY;
		$xMax = $this->_position['x'] + $offX;
		$yMax = $this->_position['y'] + $offY;

		for ($i = $y; $i <= $yMax; $i++)
		{
			for ($j = $x; $j <= $xMax; $j++)
				$aera[] = array('x' => $j, 'y' => $i);
		}
		return $aera;
	}

	public function			reset()
	{
		$this->_actived = FALSE;
		$this->resetPP();
		$this->_maneuvre = $this->_maneuvreInit;
		$this->_moved = 0;
	}

	public function			hearted($damage)
	{
		if ($damage >= ($this->_Pv + $this->_Ps))
			return TRUE;
		if ($damage <= $this->_Ps)
		{
			$this->_Ps -= $damage;
			return FALSE;
		}
		$damage -= $this->_Ps;
		$this->_Ps = 0;
		$this->_Pv -= $damage;
		return FALSE;
	}

	protected function			_go($val)
	{
		switch ($this->_position['dir'])
		{
			case 'N':
				$this->_position['y'] -= $val;
				break ;
			case 'S':
				$this->_position['y'] += $val;
				break ;
			case 'E':
				$this->_position['x'] += $val;
				break ;
			case 'W':
				$this->_position['x'] -= $val;
				break ;
		}
		if ($this->_moved === 0)
			$this->_state = 'motionless';
		else
			$this->_state = 'motion';
		$this->_lastState = $this->_state;
	}

	protected function			_tryRun($val)
	{
		if ($val > $this->_speed)
			$val = $this->_speed;
		else if ($val < $this->_maneuvre)
		{
			$val = $this->_maneuvre;
			$this->_maneuvre = 0;
		}
		else
			$this->_maneuvre = 0;
		$this->_speed -= $val;
		$this->_moved += $val;
		$this->_go($val);
		return TRUE;
	}

	protected function			_tryStop($val)
	{
		if ($this->_lastState === 'motion' AND $this->_maneuvre > 0)
			$this->_go($this->_maneuvre);
		return TRUE;
	}

	protected function			_tryLeft($val)
	{
		return FALSE;
	}

	protected function			_tryRight($val)
	{
		return FALSE;
	}

	protected function			_noMove($val)
	{
		if ($this->_lastState === 'motion' AND $this->_maneuvre > 0)
			$this->_go($this->_maneuvre);
		return TRUE;
	}

	public function				tryMove($id, $val)
	{
		if ($this->_speed === 0)
			return FALSE;
		switch ($id)
		{
			case 'run':
				return $this->_tryRun($val);
			case 'stop':
				return $this->_tryStop($val);
			case 'turnLeft':
				return $this->_tryLeft($val);
			case 'turnRight':
				return $this->_tryRight($val);
			case 'next':
				return $this->_noMove($val);
		}
		return FALSE;
	}

}

?>
