#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Colors.h"

typedef struct Enemy {
    double hp;
    int damage;
    int defense;
} Enemy;

Enemy* createEnemy() {
    Enemy* enemy = (Enemy*) malloc(sizeof(Enemy));

    SetConsoleColor(LIGHT_RED_COLOR);
    printf("Write down your enemy's stats...\n");

    SetConsoleColor(RED_COLOR);
    printf("> HP: ");

    SetConsoleColor(LIGHT_RED_COLOR);
    if(scanf("%lf", &(enemy->hp)) != 1) {
        enemy->hp = 100;
    }

    SetConsoleColor(RED_COLOR);
    printf("> Damage: ");

    SetConsoleColor(LIGHT_RED_COLOR);
    if(scanf("%d", &(enemy->damage)) != 1) {
        enemy->damage = 5;
    }

    SetConsoleColor(RED_COLOR);
    printf("> Defense: ");

    SetConsoleColor(LIGHT_RED_COLOR);
    if(scanf("%d", &(enemy->defense)) != 1) {
        enemy->defense = 1;
    }

    SetConsoleColor(RESET_COLOR);

    system("cls");

    return enemy;
}

void showEnemyStats(Enemy* user) {
    SetConsoleColor(LIGHT_RED_COLOR);
    printf("\n// Enemy Information\n");

    SetConsoleColor(RED_COLOR);
    printf("- HP: %lf\n- Damage: %d\n- Defense: %d\n", user->hp, user->damage, user->defense);
    
    getch();
    SetConsoleColor(RESET_COLOR);

    system("cls");
}

void setEnemyDamage(Enemy* target, double dmg) {
    target->hp = (target->hp - (dmg / target->defense));
}

void destroyEnemy(Enemy* target) {
    free(target);
}