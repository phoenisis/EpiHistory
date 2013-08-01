<?php

function addArc($i, $j, $v)
{
  global $arcs, $graph;

  $graph[$i][$j] = ($graph[$i][$j] == 0) ? $v : min($graph[$i][$j], $v);
  ++$arcs;

  return (0);
}

function ValidSommet($sommet)
{
  global $letters, $sommets;
  $pos = strpos($letters, $sommet);

  if ($pos >= $sommets)
    return (false);

  return ($pos);
}

function parse($lines)
{
  global $graph, $sommets;
  $nb = count($lines);

  for ($i = 0; $i < $nb; $i++)
    {
      if ($i == 0)
	{
	  $j = intval($lines[$i]);
	  if ($j < 1 || $j > 26)
	    return (1);
	  $sommets = $j;
	  for ($a = 0; $a < $sommets; ++$a)
	    for ($b = 0; $b < $sommets; ++$b)
	      $graph[$a][$b] = 0;
	}
      else
	{
	  $arc = explode(" ", $lines[$i]);

	  if (!empty($lines[$i]))
	    {
	      if (count($arc) != 3)
		return (1);
	      if (($a = ValidSommet($arc[0][0])) === false)
		return (1);
	      if (($b = ValidSommet($arc[1][0])) === false)
		return (1);
	      addArc($a, $b, intval($arc[2], 10));
	    }
	}
    }
}

function parents($x, $y)
{
  global $letters, $p;

  if ($x == $y)
    echo $letters[$x].' ';
  else
    if ($p[$y] == INF)
      echo 'Il n y a pas de chemin de x a y.';
    else
      parents($x, $p[$y]);

  echo $letters[$y].' ';
}

function showParents()
{
  global $sommets, $d;

  for ($i = 1; $i < $sommets; ++$i)
    {
      parents(0, $i);
      echo "$d[$i]\n\r";
    }
}

function algo($s, $dessin)
{
  global $letters, $sommets, $graph, $d, $p, $c;

  for ($i = 0; $i < $sommets; ++$i)
    {
      $l[] = $i;
      $d[$i] = ($i == $s) ? 0 : INF;
      $p[$i] = ($i == $s) ? 0 : INF;
    }
  while (count($l))
    {
      $c[][0] = $s;
      $k = array_keys($l);
      $x = $k[0];

    for ($i = 1; $i < count ($k); $i++)
	if ($d[$x] > $d[$k[$i]])
	  $x = $k[$i];

      for ($i = 0; $i < $sommets; ++$i)
	if ($graph[$x][$i])
	  if ($d[$x] + $graph[$x][$i] < $d[$i])
	    {
	      $d[$i] = $d[$x] + $graph[$x][$i];
	      $p[$i] = $x;
	    }

      unset($l[$x]);
    }
}
?>