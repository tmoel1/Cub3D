#!/bin/bash

for i in {1..57}; do
    map="maps/error${i}.cub"
    echo "Exécution de ./cub3d avec la carte $map"
    valgrind --leak-check=full --show-leak-kinds=all ./cub3D "$map" &> valgrind_output.txt
	./cub3D "$map"
    if ! grep -q "ERROR SUMMARY: 0 errors" valgrind_output.txt; then
        echo "Erreur détectée avec la carte $map"
    else
        echo "Aucune erreur détectée avec la carte $map"
    fi
    echo "Test terminé pour $map"
    echo "-------------------------"
done