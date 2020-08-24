// Fill out your copyright notice in the Description page of Project Settings.


#include "PongStateBase.h"

APongStateBase::APongStateBase():
    PlayerScore(0),
    OpponentScore(0)
{}

void APongStateBase::SetScore(const int32 ScoreP, int& ScoreToSet)
{
    ScoreToSet = ScoreP;
}

int32 APongStateBase::GetPlayerScore() const
{
    return PlayerScore;
}

int32 APongStateBase::GetOpponentScore() const
{
    return OpponentScore;
}

void APongStateBase::SetPlayerScore(const int32 ScoreP)
{
    SetScore(ScoreP, PlayerScore);
}

void APongStateBase::SetOpponentScore(const int32 ScoreP)
{
    SetScore(ScoreP, OpponentScore);
}
