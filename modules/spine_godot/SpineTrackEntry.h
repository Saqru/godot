/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated January 1, 2020. Replaces all prior versions.
 *
 * Copyright (c) 2013-2020, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef GODOT_SPINETRACKENTRY_H
#define GODOT_SPINETRACKENTRY_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineAnimation.h"

class SpineTrackEntry : public Reference {
	GDCLASS(SpineTrackEntry, Reference);

protected:
	static void _bind_methods();

private:
	spine::TrackEntry *track_entry;

public:
	SpineTrackEntry();
	~SpineTrackEntry();

	inline void set_spine_object(spine::TrackEntry *t) {
		track_entry = t;
	}
	inline spine::TrackEntry *get_spine_object() {
		return track_entry;
	}

	enum MixBlend {
		MIXBLEND_SETUP = 0,
		MIXBLEND_FIRST,
		MIXBLEND_REPLACE,
		MIXBLEND_ADD
	};

	int get_track_index();

	Ref<SpineAnimation> get_animation();

	bool get_loop();
	void set_loop(bool v);

	bool get_hold_previous();
	void set_hold_previous(bool v);

	bool get_reverse();
	void set_reverse(bool v);

	float get_delay();
	void set_delay(float v);

	float get_track_time();
	void set_track_time(float v);

	float get_track_end();
	void set_track_end(float v);

	float get_animation_start();
	void set_animation_start(float v);

	float get_animation_last();
	void set_animation_last(float v);

	float get_animation_time();

	float get_time_scale();
	void set_time_scale(float v);

	float get_alpha();
	void set_alpha(float v);

	float get_event_threshold();
	void set_event_threshold(float v);

	float get_attachment_threshold();
	void set_attachment_threshold(float v);

	float get_draw_order_threshold();
	void set_draw_order_threshold(float v);

	Ref<SpineTrackEntry> get_next();

	bool is_complete();

	float get_mix_time();
	void set_mix_time(float v);

	float get_mix_duration();
	void set_mix_duration(float v);

	MixBlend get_mix_blend();
	void set_mix_blend(MixBlend v);

	Ref<SpineTrackEntry> get_mixing_from();
	Ref<SpineTrackEntry> get_mixing_to();

	void reset_rotation_directions();
};

VARIANT_ENUM_CAST(SpineTrackEntry::MixBlend);
#endif//GODOT_SPINETRACKENTRY_H
