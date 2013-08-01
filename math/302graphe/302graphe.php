#!/usr/bin/php

<?php

require './require/funct.php';

if ($argv[1]){

  $fd = fopen($argv[1], 'r');

    echo "File : ".$argv[1]."\n";
    $i = -1;
    $points = array();

    while ($line = trim(fgets($fd))){
	if ($i < 0){
	    $nbArc = $line;
	    echo " Nombre d'arcs : $nbArc\n";
	  }

	else{
	    echo "$line\n";
	    $tmp = split(' ', $line);
	    $points[$i][0] = $tmp[0];
	    $points[$i][1] = $tmp[1];
	  }
	$i++;
      }

    $top = topCounter($points);
    echo "\nMatrice d'adjacence :\n";
    $matrix = calcAdjMatrix($points, $top);

    echo "\nMatrice d'adjacence de G2:\n";
    calcSquareMatrix($matrix);
    echo "\n Matrice d'accessibilité :";
    calcAccessibility($points);
  }

 else
   echo "Require : ./302graphe.php file.txt \n \t\t or \n\t  php 302graphe.php file.txt\n";

  ?>
