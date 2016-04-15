<?php
Class Player {

	private $playerName;
	private $fleetName;

	Public function __construct ( array $kwargs ) {
		if ($kwargs['playerName']) {
			$this->playerName = $kwargs['playerName'];
			print ("Player " . $this->playerName . " created..." . PHP_EOL);
			if ($kwargs['fleetName'])
				$this->fleetName = $kwargs['fleetName'];
			else
				$this->fleetName = $kwargs['playerName'] . '\'s fleet';
		}
	}



	public function __toString() {
		print ('Player Name: ' . $this->playerName . PHP_EOL);
		return sprintf ("");
	}
}

?>
