<?php
require_once("include.php");

//var_dump($_SESSION);



$data = array(
  array(
    'pos'=>array('x'=>10, 'y'=>50),
    'orient' => "south",
    'size' => array(1 ,3)
  ),
  array(
    'pos'=>array('x'=>20, 'y'=>10),
    'orient' => "south",
    'size' => array(1 ,3)
  ),
  array(
    'pos'=>array('x'=>30, 'y'=>70),
    'orient' => "south",
    'size' => array(1 ,3)
  ),
  array(
    'pos'=>array('x'=>50, 'y'=>50),
    'orient' => "south",
    'size' => array(1 ,3)
  ),
  array(
    'pos'=>array('x'=>75, 'y'=>50),
    'orient' => "south",
    'size' => array(1 ,3)
  )
);

if (isset($_SESSION['board']))
{
  $board = unserialize($_SESSION['board']);

  if (isset($_GET['get']) && $_GET['get'] == "asteroid") {
    echo json_encode($board->sendAsteroid());
  }
  else if (isset($_GET['get']) && $_GET['get'] == "ships") {
    $ship = $board->sendShips();
    echo json_encode($ship);
  }


  if (isset($_GET['get']) && $_GET['get'] == "ship" && isset($_GET['class']))
  {
    $class = $_GET['class'];
    $tab = explode(' ',$class);
    $owner = $tab[2][1];
    $tab = explode('_',$tab[1]);
    $case = array('x' => $tab[1], 'y' => $tab[2]);
    echo $owner;



    $idShip = $board->getMap($case['x'],$case['y']);
    $ship = $board->getShipById($idShip);
    if (!$ship->getOwner() == $owner)
    {
      echo "Enemy Ship";
    }
?>
        <div class="sub-panel">
          <div class="sub-panel-head">
            Order <?php echo $ship->getName(); ?>
          </div>
          <div style="display:flex;">
            <div class="viewer " id="PPleft">PP dispo:<?php echo $ship->getPpCurr(); ?></div>
            <div class="viewer btn-rouge panel-btn" id="PVleft">PV restant:<?php echo $ship->getPvCurr(); ?></div>
            <div class="viewer btn-rouge panel-btn" id="Shield">Shield Value</div>
            <div class="viewer btn-rouge panel-btn" id="Speed">Speed Value:<?php echo $ship->get_speedCurr(); ?></div>
          </div>
          <div style="display:flex;">
            <div class="viewer btn-rouge panel-btn">Next</div>
            <div class="viewer gun btn-rouge panel-btn" id="gun1">Charge 3</div>
            <div class="viewer gun btn-rouge panel-btn" id="gun2">Charge w2</div>
            <div class="viewer gun btn-rouge panel-btn" id="gun3">Charge w3</div>
          </div>
        </div>
        <div class="sub-panel">
          <div class="sub-panel-head">
            Movement
          </div>
          <div style="display:flex;">
            <div class="viewer panel-btn" id="Vitesse">Manoeuvre:<?php echo getManeuvrability; ?></div>
            <div class="viewer panel-btn" id="PVleft"></div>
            <div class="viewer" id="Shield"><input type="text" id="nb"></div>
            <div class="viewer panel-btn" id="Speed">Speed Value</div>
          </div>

          <div style="display:flex;">
            <div class="viewer panel-btn" id="run">Run</div>
            <div class="viewer panel-btn" id="turnLeft">Turn Left</div>
            <div class="viewer panel-btn" id="turnRight">Turn Right</div>
            <div class="viewer panel-btn" id="stop">Stop</div>
          </div>

        </div>
        <div class="sub-panel">
          <div class="sub-panel-head">
            Attack
          </div>
        </div>
<?php
  }
  if (isset($_GET['action']) && $_GET['action'] == "btn")
  {

		while ($this->tryMove($_GET['id'], $_GET['nb']) === FALSE)
			echo "Can't move like this!";
	
          //$this->run($_GET['nb']);
          echo $_GET['id'];
          echo $_GET['nb'];
  }


}




?>
