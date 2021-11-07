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

#ifndef GODOT_SPINEATLASRESOURCE_H
#define GODOT_SPINEATLASRESOURCE_H


#include "core/variant_parser.h"
#include "core/io/resource_loader.h"
#include "core/io/resource_saver.h"
#include "core/io/image_loader.h"
#include "scene/resources/texture.h"

#include <spine/SpineString.h>
#include <spine/TextureLoader.h>
#include <spine/Atlas.h>
#include "SpineRendererObject.h"

class SpineAtlasResource : public Resource {
	GDCLASS(SpineAtlasResource, Resource);

protected:
	static void _bind_methods();

	spine::Atlas *atlas;

	String source_path;
	String atlas_data;
	String normal_texture_prefix;

	Array textures;
	Array normal_maps;

public:
	inline String &get_atlas_data() { return atlas_data; }

	inline spine::Atlas *get_spine_atlas() { return atlas; }

	inline void set_normal_texture_prefix(const String &p) { normal_texture_prefix = p; }

	Error load_from_atlas_file(const String &p_path);// .atlas

	Error load_from_file(const String &p_path);// .spatlas
	Error save_to_file(const String &p_path);  // .spatlas

	String get_source_path();
	Array get_textures();
	Array get_normal_maps();

	SpineAtlasResource();
	virtual ~SpineAtlasResource();
};

class SpineAtlasResourceFormatLoader : public ResourceFormatLoader {
GDCLASS(SpineAtlasResourceFormatLoader, ResourceFormatLoader);

public:
	virtual RES load(const String &p_path, const String &p_original_path, Error *r_error = NULL);
	virtual void get_recognized_extensions(List<String> *r_extensions) const;
	virtual bool handles_type(const String &p_type) const;
	virtual String get_resource_type(const String &p_path) const;
};

class SpineAtlasResourceFormatSaver : public ResourceFormatSaver {
GDCLASS(SpineAtlasResourceFormatSaver, ResourceFormatSaver);

public:
	Error save(const String &p_path, const RES &p_resource, uint32_t p_flags = 0) override;
	void get_recognized_extensions(const RES &p_resource, List<String> *p_extensions) const override;
	bool recognize(const RES &p_resource) const override;
};


#endif//GODOT_SPINEATLASRESOURCE_H
