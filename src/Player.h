#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Colors.h"

typedef struct Player {
    char* playerName;
    double hp;
    int damage;
    int defense;
    int option;
} Player;

Player* createPlayer() {
    Player* player = (Player*) malloc(sizeof(Player));
    player->playerName = malloc(sizeof(char) * 50);
    player->option = 0;

    SetConsoleColor(CYAN_COLOR);
    printf("Write down your character's stats...\n");

    SetConsoleColor(BLUE_COLOR);
    printf("> Character name: ");

    SetConsoleColor(CYAN_COLOR);
    if(scanf("%s", player->playerName) != 1) {
        strcpy(player->playerName, "Nameless");
    }

    SetConsoleColor(BLUE_COLOR);
    printf("> HP: ");

    SetConsoleColor(CYAN_COLOR);
    if(scanf("%lf", &(player->hp)) != 1) {
        player->hp = 100;
    }

    SetConsoleColor(BLUE_COLOR);
    printf("> Damage: ");

    SetConsoleColor(CYAN_COLOR);
    if(scanf("%d", &(player->damage)) != 1) {
        player->damage = 5;
    }
    
    SetConsoleColor(BLUE_COLOR);
    printf("> Defense: ");

    SetConsoleColor(CYAN_COLOR);
    if(scanf("%d", &(player->defense)) != 1) {
        player->defense = 1;
    }

    SetConsoleColor(RESET_COLOR);

    system("cls");

    return player;
}

void showPlayerStats(Player* user) {
    SetConsoleColor(LIGHT_GREEN_COLOR);
    printf("\n// Character Information\n");

    SetConsoleColor(LIGHT_BLUE_COLOR);
    printf("- Character name: %s\n- HP: %lf\n- Damage: %d\n- Defense: %d\n", user->playerName, user->hp, user->damage, user->defense);

    getch();
    SetConsoleColor(RESET_COLOR);

    system("cls");
}

void setPlayerDamage(Player* target, double dmg) {
    target->hp = (target->hp - (dmg / target->defense));
}

void destroyPlayer(Player* player) {
    free(player->playerName);
    free(player);
}