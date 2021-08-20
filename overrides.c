#include "main.h"
#include "overrides.h"
#include "overrides/gambatte.h"
#include "overrides/gpsp.h"
#include "overrides/mame2000.h"
#include "overrides/pcsx_rearmed.h"
#include "overrides/snes9x2002.h"
#include "overrides/snes9x2005.h"

static const struct core_override overrides[] = {
	gambatte_overrides,
	gpsp_overrides,
	mame2000_overrides,
	pcsx_rearmed_overrides,
	snes9x2002_overrides,
	snes9x2005_overrides,
};

static const struct core_override *override;

const struct core_override *get_overrides(void) {
	return override;
}

void set_overrides(const char *core_name) {
	override = NULL;

	for (int i = 0; i < array_size(overrides); i++) {
		if (!strcmp(core_name, overrides[i].core_name)) {
			override = &overrides[i];
			break;
		}
	}
}