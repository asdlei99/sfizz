// SPDX-License-Identifier: BSD-2-Clause

// This code is part of the sfizz library and is licensed under a BSD 2-clause
// license. You should have receive a LICENSE.md file along with the code.
// If not, contact the sfizz maintainers at https://github.com/sfztools/sfizz

#pragma once

#include "Config.h"
#include "Voice.h"
#include "SisterVoiceRing.h"
#include <vector>
#include "absl/types/span.h"

namespace sfz
{
class VoiceStealing
{
public:
    VoiceStealing();
    /**
     * @brief Propose a voice to steal from a set of voices
     *
     * @param voices
     * @return Voice*
     */
    Voice* steal(absl::Span<Voice*> voices) noexcept;
private:
    struct VoiceScore
    {
        Voice* voice;
        double score;
    };

    struct VoiceScoreComparator
    {
        bool operator()(const VoiceScore& voiceScore, const double& score)
        {
            return (voiceScore.score < score);
        }

        bool operator()(const double& score, const VoiceScore& voiceScore)
        {
            return (score < voiceScore.score);
        }

        bool operator()(const VoiceScore& lhs, const VoiceScore& rhs)
        {
            return (lhs.score < rhs.score);
        }
    };
    std::vector<VoiceScore> voiceScores;
};
}
