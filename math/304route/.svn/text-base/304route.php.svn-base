#!/usr/bin/php

<?php
Require './require/func.php';

$letters = 'abcdefghijklmnopqrstuvwxyz';
$sommets;
$arcs;
$graph;
$d;
$p;
$c;
$nom;

function aff1()
{
  global  $nom, $sommets, $arcs;

  echo "Nom du fichier : $nom\n\r";
  echo "Nombre de sommets : $sommets\n\r";
  echo "Nombrd d'arcs : $arcs \n\r";
}

if ($argc != 2)
  die("Usage: php 304route.php filename\n\r");

$nom = $argv[1];
$content = file_get_contents($argv[1]);
$lines = explode("\n", $content);
unset($content);

if (parse($lines))
  die("Error on parse\n\r");

aff1();

for ($i = 1; $i < count($lines) && !empty($lines[$i]); $i++)
  echo $lines[$i]."\n\r";

unset($lines);
algo(0, 0);
unset($graph);
echo "Plus courts chemins : \n\r";

for ($i = 0; $i < $sommets; ++$i)
  echo $letters[$i].' ';

echo "\n\r";

for ($i = 0; $i < $sommets; ++$i)
  echo $d[$i].' ';

echo "\n\r";
showParents();

?>