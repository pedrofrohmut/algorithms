#! /usr/bin/env bash

while true; do
    echo -e "\nPress 'r' to restart, or 'q' to exit"
    read -n 1 key

    case $key in
        [Rr])
            clear
            ./gradlew build
            ;;
        [Qq])
            exit 0
            ;;
        *)
            ;;
    esac
done
