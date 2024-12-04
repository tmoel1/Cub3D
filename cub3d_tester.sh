#!/bin/bash

for i in {1..55}; do
    map="maps/error${i}"
    echo "Exécution de ./cub3d avec la carte $map"
    valgrind --leak-check=full ./cub3d "$map" &> valgrind_output.txt
	./cub3d "$map"
    if ! grep -q "ERROR SUMMARY: 0 errors" valgrind_output.txt; then
        echo "Erreur détectée avec la carte $map"
    else
        echo "Aucune erreur détectée avec la carte $map"
    fi
    echo "Test terminé pour $map"
    echo "-------------------------"
done