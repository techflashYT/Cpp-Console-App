#pragma once
#include <iostream>
#include <cstring>
#include <cstdint>
#include <sstream>
#include "defines.hpp"
#include "achievementDefines.hpp"
// IDEA: Sound that plays for getting an achievement?
struct AchievementList {
	char name[MAX_ACHIEVEMENTS][50]{{ACHIEVEMENT1_NAME}, {ACHIEVEMENT2_NAME}};
	// IDEA: Icon?
	char description[MAX_ACHIEVEMENTS][50]{{ACHIEVEMENT1_DESCRIPTION}, {ACHIEVEMENT2_DESCRIPTION}};
	uint_fast8_t rank[MAX_ACHIEVEMENTS]{ACHIEVEMENT1_RANK, ACHIEVEMENT2_RANK};  // 0: Default, 1: Bronze, 2: Silver, 3: Gold, 4: Platinum, 5: ? for HUGE achievements (e.g. beating final boss, etc)
	uint_fast64_t dateEarned[MAX_ACHIEVEMENTS]{0};
	bool isCollected[MAX_ACHIEVEMENTS]{false};
} achievementList;
struct Achievement {
	char name[50]{};
	char description[50]{};
	uint_fast8_t rank = 0;  // 0: Default, 1: Bronze, 2: Silver, 3: Gold, 4: Platinum, 5: ? for HUGE achievements (e.g. beating final boss, etc)
	uint_fast64_t dateEarned = 0;
	bool isCollected = false;
} achievement;
struct Achievements {
	struct Strings {
		const char* gotAchievementNormal   = "You got an achievement: ";
		const char* gotAchievementBronze   = "You got a bronze achievement: ";
		const char* gotAchievementSilver   = "You got a silver achievement: ";
		const char* gotAchievementGold     = "You got a gold achievement: ";
		const char* gotAchievementPlatinum = "You got a platinum achievement: ";
		const char* gotAchievementUltra    = "You got a ULTRA achievement: ";
	} strings;
	Achievement* getAchievementByID(uint_fast8_t id) {
		// Check if ID is bigger than MAX_ACHIEVEMENTS.
		if (id < MAX_ACHIEVEMENTS) {
			strcpy_s(achievement.name, achievementList.name[id]);
			strcpy_s(achievement.description, achievementList.description[id]);
			achievement.rank = *achievementList.rank;
			achievement.dateEarned = *achievementList.dateEarned;
			achievement.isCollected = *achievementList.isCollected;
			return &achievement;
		}
		else {
			std::stringstream errStream;
			errStream << "Invalid achievement ID (" << id << ") was referenced, please report this to the developer.";
			char err[90];
			errStream >> err;
			throw std::invalid_argument(err);
		}
	}
	uint_fast8_t earn(uint_fast8_t id) {
		uint_fast8_t rank = getAchievementByID(id)->rank;
		getAchievementByID(id)->isCollected = true;
		if (rank == 0) {
			try {
				if (logLevel == DEBUG) {
					printf_s("%sAchievement Details:\r\n%sName: %s\r\n%sDescription: %s\r\n%sRank: %u\r\n%sDate Earned: %u\r\n%sCollected: %s\r\n",
					logLevel[DEBUG],
					logLevel[DEBUG], getAchievementByID(id)->name,
					logLevel[DEBUG], getAchievementByID(id)->description,
					logLevel[DEBUG], getAchievementByID(id)->rank,
					logLevel[DEBUG], getAchievementByID(id)->dateEarned,
					logLevel[DEBUG], getAchievementByID(id)->isCollected ? "true" : "false");
				}
				printf_s("%s\"%s\"!\r\n", strings.gotAchievementNormal, getAchievementByID(id)->name);
			}
			catch (...) {
				return 1;
			}
		}
		else if (rank == 1) {
			try {
				printf_s("%s\"%s\"!\r\n", strings.gotAchievementBronze, getAchievementByID(id)->name);
			}
			catch (...) {
				return 1;
			}
		}
		else if (rank == 2) {
			try {
				printf_s("%s\"%s\"!\r\n", strings.gotAchievementSilver, getAchievementByID(id)->name);
			}
			catch (...) {
				return 1;
			}
		}
		else if (rank == 3) {
			try {
				printf_s("%s\"%s\"!\r\n,", strings.gotAchievementGold, getAchievementByID(id)->name);
			}
			catch (...) {
				return 1;
			}
		}
		else if (rank == 4) {
			try {
				printf_s("%s\"%s\"! WOW!\r\n", strings.gotAchievementPlatinum, getAchievementByID(id)->name);
			}
			catch (...) {
				return 1;
			}
		}
		else if (rank == 5) {
			try {
				printf_s("%s\"%s\"!\r\n", strings.gotAchievementUltra, getAchievementByID(id)->name);
			}
			catch (...) {
				return 1;
			}
		}

		return 0;
	}
} achievements;
