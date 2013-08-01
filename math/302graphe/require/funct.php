<?php

function        fillTab($points)
{
  $tabAsso = array();

  for ($i = 0, $count = 0 ; $points[$i] != NULL; $i++){
    if ($i == 0){
      $ref = $points[$i][0];
      $tabAsso[$ref] = $count++;
    }

    elseif ($ref != $points[$i][0]){
      $ref = $points[$i][0];
      $tabAsso[$ref] = $count++;
    }
  }

  return $tabAsso;
}

function        Linked($linked, $point)
{
  $len = strlen($point);

  foreach ($linked as $key => $value)
    if (!strncmp($key, $point, $len) || !strncmp($value, $point, $len))
      return true;

  return false;
}

function        calcAccessibility($points)
{
  global  $top;
  global  $tabAsso;

  $assoMatrix = array();
  $assoMatrix = zero($assoMatrix, $top);
  $linked = array();

  foreach ($tabAsso as $key => $value){
    $linked[$value][$key] = $key;
    $assoMatrix[$value][$value] = 1;
    for ($j = 0, $i = 1; $points[$j] != NULL; $j++){
      if (Linked($linked[$value], $points[$j][0])){
	$assoMatrix[$value][$tabAsso[$points[$j][1]]] = '1';
	if (!Linked($linked[$value], $points[$j][1])){
	  if ($linked[$value][$points[$j][0]] == NULL)
	    $linked[$value][$points[$j][0]] = $points[$j][1];
	  else
	    $linked[$value][$points[$j][0] . $i++] = $points[$j][1];
	  if ($linked[$tabAsso[$points[$j][1]]] != NULL){
	    $len = strlen($points[$j][1]);
	    foreach ($linked[$tabAsso[$points[$j][1]]] as $key => $val){
	      if ($key != $val && !strncmp($key, $points[$j][1], $len)){
		$assoMatrix[$value][$tabAsso[$val]] = '1';
	      }
	    }
	  }
	}
      }
    }
  }

  echo "\n";
  displayMatrix($assoMatrix);
}

function        zero($matrix, $size)
{
  for($i = 0; $i < $size ; $i++)
    for ($j = 0 ; $j < $size ; $j++)
      $matrix[$i][$j] = '0';

  return $matrix;
}

function        displayMatrix($matrix)
{
  global  $top;

  for ($i = 0 ; $i < $top ; $i++){
    echo "\t";
    for ($j = 0 ; $j < $top; $j++)
      echo $matrix[$i][$j];
    echo "\n";
  }

}

function        multMat($matrix, $x, $y)
{
  global  $top;

  $res = 0;

  for ($i = 0, $j = 0; $i < $top ; $i++, $j++)
    $res += $matrix[$x][$i] * $matrix[$j][$y];

  return $res;
}

function        calcSquareMatrix($matrix)
{
  global  $top;

  $SqMatrix = array();
  $SqMatrix = zero($SqMatrix, $top);

  for ($i = 0 ; $i < $top ; $i++){
    for ($j = 0; $j < $top ; $j++)
      $SqMatrix[$i][$j] = multMat($matrix, $i, $j);

  }

  displayMatrix($SqMatrix);
}

function        calcAdjMatrix($points, $top)
{
  global  $top;
  global  $tabAsso;
  $matrix = array();
  $matrix = zero($matrix, $top);
  $tabAsso = fillTab($points);

  for($i = 0; $points[$i] != NULL ; $i++)
    $matrix[$tabAsso[$points[$i][0]]][$tabAsso[$points[$i][1]]] = '1';

  displayMatrix($matrix);

  return $matrix;
}

function        checkTop($ref, $top)
{
  for ($i = 0; $ref[$i] != NULL; $i++)
    if ($ref[$i] == $top)
      return false;

  return true;
}

function        topCounter($points)
{
  $ref = array();
  $ref = $points[0][0];
  $count = 1;

  for ($i = 0; $points[$i]; $i++)
    for($j = 0; $points[$i][$j]; $j++)
      if (checkTop($ref, $points[$i][$j])){
	$ref[$count] = $points[$i][$j];
	$count++;
      }

  echo "Nombre de sommets : $count\n";
  return $count;
}
?>