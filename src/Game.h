#pragma once

#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Enemy.h"
#include "Colors.h"

void damagePlayer(Enemy* user, Player* target) {
    srand(time(NULL));
    setPlayerDamage(target, (user->damage * (rand() % 2 + 1)));
}

void damageEnemy(Player* user, Enemy* target) {
    srand(time(NULL));
    setEnemyDamage(target, (user->damage * (rand() % 2 + 1)));
}

int validateTurnOption(int option) {
    if(option > 0 && option < 5) return 1;
    return 0;
}

void executeTurn(Player* player, Enemy* enemy) {
    srand(time(NULL));

    int opt;

    switch(player->option) {
        case 1:
        if(rand() % 2 + 1 == 2) {
            SetConsoleColor(LIGHT_RED_COLOR);
            printf("The enemy has successfully dodged the attack!\n");
            SetConsoleColor(RESET_COLOR);

            return;
        }

        SetConsoleColor(LIGHT_GREEN_COLOR);
        printf("%s managed to punch his enemy!\n", player->playerName);
        SetConsoleColor(RESET_COLOR);

        damageEnemy(player, enemy);

        break;

        case 2:
        SetConsoleColor(LIGHT_GREEN_COLOR);
        printf("%s has successfully dodge the attack!\n", player->playerName);
        SetConsoleColor(RESET_COLOR);

        return;

        case 3:

        SetConsoleColor(LIGHT_GREEN_COLOR);
        printf("%s has decided to rest...\n", player->playerName);
        SetConsoleColor(RESET_COLOR);

        break;

        case 4:
        SetConsoleColor(LIGHT_CYAN_COLOR);
        printf("What do you want to analyze?\n1 - Player\n2 - Enemy\n> ");

        SetConsoleColor(BLUE_COLOR);
        scanf("%d", &opt);

        if(opt == 1) {
            showPlayerStats(player);
        } else {
            showEnemyStats(enemy);
        }

        getch();
        SetConsoleColor(RESET_COLOR);

        return;
    }

    SetConsoleColor(LIGHT_RED_COLOR);
    printf("The enemy has punched you!\n");

    damagePlayer(enemy, player);

    SetConsoleColor(RESET_COLOR);
}

void turn(Player* user, Enemy* enemy) {
    SetConsoleColor(BLUE_COLOR);

    printf("1 - Attack\n2 - Dodge\n3 - Rest\n4 - Analyze\n> ");
    scanf("%d", &(user->option));

    if(validateTurnOption(user->option) == 1) {
        executeTurn(user, enemy);
        return;
    }

    SetConsoleColor(RED_COLOR);
    printf("\n- Invalid option...\n");

    SetConsoleColor(RESET_COLOR);
    turn(user, enemy);
}