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

#ifndef GODOT_SPINESLOTDATA_H
#define GODOT_SPINESLOTDATA_H
#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineBoneData.h"

class SpineSlotData : public Reference {
	GDCLASS(SpineSlotData, Reference);

protected:
	static void _bind_methods();

private:
	spine::SlotData *slot_data;

public:
	SpineSlotData();
	~SpineSlotData();

	inline void set_spine_object(spine::SlotData *s) {
		slot_data = s;
	}
	inline spine::SlotData *get_spine_object() {
		return slot_data;
	}

	enum BlendMode {
		BLENDMODE_NORMAL = 0,
		BLENDMODE_ADDITIVE,
		BLENDMODE_MULTIPLY,
		BLENDMODE_SCREEN
	};

	int get_index();

	String get_slot_name();

	Ref<SpineBoneData> get_bone_data();

	Color get_color();
	void set_color(Color c);

	Color get_dark_color();
	void set_dark_color(Color c);

	bool has_dark_color();
	void set_has_dark_color(bool v);

	String get_attachment_name();
	void set_attachment_name(const String &v);

	BlendMode get_blend_mode();
	void set_blend_mode(BlendMode v);
};

VARIANT_ENUM_CAST(SpineSlotData::BlendMode);
#endif//GODOT_SPINESLOTDATA_H
