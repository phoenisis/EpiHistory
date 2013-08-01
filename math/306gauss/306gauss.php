#!/usr/local/bin/php

<?php
require "require/func.php";

function usage() {
  echo "\033[31mUsage : ./306gauss <filename> [options]\n";
  echo "\toptions :\n";
  echo "\t\t0 : prend le premier pivot superieur a 0.\n";
  echo "\t\t0 : prend le pivot qui a la valeur absolue la plus grande.\n";
}

function getFile($filename, &$size, &$matrix, &$vector)
{
  if (!file_exists($filename)) {
    echo "File \033[31m $filename\033[0m does not exist\n";
    exit();
  }

  if (($file = fopen($filename, "r")) == FALSE) {
    echo "\033[31mCan not open file :\033[33m $filename\033[0m\n";
    exit();
  }

  echo "Fichier :\033[31m $filename\033[0m\n";
  $data = fread($file, filesize($filename));
  getDataFile($data, $size, $matrix, $vector);
  fclose($file);
}

($argc == 2 || $argc == 3) ? (($argc == 3) ? gauss($argv[1], $argv[2]) : gauss($argv[1])) : usage();
?>