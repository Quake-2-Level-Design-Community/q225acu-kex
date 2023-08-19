#include "m_soldierh.h"

static int	h_sound_idle;
static int	h_sound_sight1;
static int	h_sound_sight2;
static int	h_sound_cock;
static int	h_sound_pain_ripper;
static int	h_sound_pain_hypergun;
static int	h_sound_pain_lasergun;
static int	h_sound_death_ripper;
static int	h_sound_death_hypergun;
static int	h_sound_death_lasergun;
static int	h_sound_hypergun_loop = 0;
static int	h_sound_hypergun_spindown = 0;
static int	h_sound_lasergun_fire = 0;

void soldierh_idle (edict_t *self)
{
	if (!(self->spawnflags & SPAWNFLAG_MONSTER_AMBUSH))
	{
		if (frandom() > 0.8)
			gi.sound (self, CHAN_VOICE, h_sound_idle, 1, ATTN_IDLE, 0);
	}
}

void soldierh_cock (edict_t *self)
{
	if (self->s.frame == FRAME_stand322)
		gi.sound (self, CHAN_WEAPON, h_sound_cock, 1, ATTN_IDLE, 0);
	else
		gi.sound (self, CHAN_WEAPON, h_sound_cock, 1, ATTN_NORM, 0);
}

// STAND

void soldierh_stand (edict_t *self);

mframe_t soldierh_frames_stand1 [] =
{
	{ai_stand, 0, soldierh_idle},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},

	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},

	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL}
};
mmove_t soldierh_move_stand1 = {FRAME_stand101, FRAME_stand130, soldierh_frames_stand1, soldierh_stand};

mframe_t soldierh_frames_stand3 [] =
{
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},

	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},

	{ai_stand, 0, NULL},
	{ai_stand, 0, soldierh_cock},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},

	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL}
};
mmove_t soldierh_move_stand3 = {FRAME_stand301, FRAME_stand339, soldierh_frames_stand3, soldierh_stand};


void soldierh_stand (edict_t *self)
{
	if ((self->monsterinfo.active_move.pointer() == &soldierh_move_stand3) || (frandom() < 0.8))
		M_SetAnimation(self, &soldierh_move_stand1);
	else
		M_SetAnimation(self, &soldierh_move_stand3);
}


//
// WALK
//

void soldierh_walk1_random (edict_t *self)
{
	if (frandom() > 0.1)
		self->monsterinfo.nextframe = FRAME_walk101;
}

mframe_t soldierh_frames_walk1 [] =
{
	{ai_walk, 3, NULL},
	{ai_walk, 6, NULL},
	{ai_walk, 2, NULL},
	{ai_walk, 2, NULL},
	{ai_walk, 2, NULL},
	{ai_walk, 1, NULL},
	{ai_walk, 6, NULL},
	{ai_walk, 5, NULL},
	{ai_walk, 3, NULL},
	{ai_walk, -1, soldierh_walk1_random},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0, NULL},
	{ai_walk, 0,  NULL}
};
mmove_t soldierh_move_walk1 = {FRAME_walk101, FRAME_walk133, soldierh_frames_walk1, NULL};

mframe_t soldierh_frames_walk2 [] =
{
	{ai_walk, 4, NULL},
	{ai_walk, 4, NULL},
	{ai_walk, 9, NULL},
	{ai_walk, 8, NULL},
	{ai_walk, 5, NULL},
	{ai_walk, 1, NULL},
	{ai_walk, 3, NULL},
	{ai_walk, 7, NULL},
	{ai_walk, 6, NULL},
	{ai_walk, 7,  NULL}
};
mmove_t soldierh_move_walk2 = {FRAME_walk209, FRAME_walk218, soldierh_frames_walk2, NULL};

void soldierh_walk (edict_t *self)
{
	if (frandom() < 0.5)
		M_SetAnimation(self, &soldierh_move_walk1);
	else
		M_SetAnimation(self, &soldierh_move_walk2);
}


//
// RUN
//

void soldierh_run (edict_t *self);

mframe_t soldierh_frames_start_run [] =
{
	{ai_run, 7,  NULL},
	{ai_run, 5,  NULL}
};
mmove_t soldierh_move_start_run = {FRAME_run01, FRAME_run02, soldierh_frames_start_run, soldierh_run};

mframe_t soldierh_frames_run [] =
{
	{ai_run, 10, NULL},
	{ai_run, 11, NULL},
	{ai_run, 11, NULL},
	{ai_run, 16, NULL},
	{ai_run, 10, NULL},
	{ai_run, 15, NULL}
};
mmove_t soldierh_move_run = {FRAME_run03, FRAME_run08, soldierh_frames_run, NULL};

void soldierh_run (edict_t *self)
{
	if (self->monsterinfo.aiflags & AI_STAND_GROUND)
	{
		M_SetAnimation(self, &soldierh_move_stand1);
		return;
	}

	if (self->monsterinfo.active_move.pointer() == &soldierh_move_walk1 ||
		self->monsterinfo.active_move.pointer() == &soldierh_move_walk2 ||
		self->monsterinfo.active_move.pointer() == &soldierh_move_start_run)
	{
		M_SetAnimation(self, &soldierh_move_run);
	}
	else
	{
		M_SetAnimation(self, &soldierh_move_start_run);
	}
}


//
// JUMP
//

mframe_t soldierh_frames_jump [] =
{
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, 0, NULL}
};
mmove_t soldierh_move_jump = { FRAME_run01, FRAME_run08, soldierh_frames_jump, soldierh_run };

void soldierh_jump (edict_t *self)
{
	M_SetAnimation(self, &soldierh_move_jump);
}


//
// PAIN
//

mframe_t soldierh_frames_pain1 [] =
{
	{ai_move, -3, NULL},
	{ai_move, 4, NULL},
	{ai_move, 1, NULL},
	{ai_move, 1, NULL},
	{ai_move, 0, NULL}
};
mmove_t soldierh_move_pain1 = {FRAME_pain101, FRAME_pain105, soldierh_frames_pain1, soldierh_run};

mframe_t soldierh_frames_pain2 [] =
{
	{ai_move, -13, NULL},
	{ai_move, -1, NULL},
	{ai_move, 2,  NULL},
	{ai_move, 4,  NULL},
	{ai_move, 2,  NULL},
	{ai_move, 3,  NULL},
	{ai_move, 2,  NULL}
};
mmove_t soldierh_move_pain2 = {FRAME_pain201, FRAME_pain207, soldierh_frames_pain2, soldierh_run};

mframe_t soldierh_frames_pain3 [] =
{
	{ai_move, -8, NULL},
	{ai_move, 10, NULL},
	{ai_move, -4, NULL},
	{ai_move, -1, NULL},
	{ai_move, -3, NULL},
	{ai_move, 0, NULL},
	{ai_move, 3, NULL},
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, 1, NULL},
	{ai_move, 0, NULL},
	{ai_move, 1, NULL},
	{ai_move, 2, NULL},
	{ai_move, 4, NULL},
	{ai_move, 3, NULL},
	{ai_move, 2, NULL}
};
mmove_t soldierh_move_pain3 = {FRAME_pain301, FRAME_pain318, soldierh_frames_pain3, soldierh_run};

mframe_t soldierh_frames_pain4 [] =
{
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, -10, NULL},
	{ai_move, -6, NULL},
	{ai_move, 8,  NULL},
	{ai_move, 4,  NULL},
	{ai_move, 1,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 2,  NULL},
	{ai_move, 5,  NULL},
	{ai_move, 2,  NULL},
	{ai_move, -1, NULL},
	{ai_move, -1, NULL},
	{ai_move, 3,  NULL},
	{ai_move, 2,  NULL},
	{ai_move, 0,  NULL}
};
mmove_t soldierh_move_pain4 = {FRAME_pain401, FRAME_pain417, soldierh_frames_pain4, soldierh_run};

void soldierh_pain (edict_t *self, edict_t *other, float kick, int damage)
{
	float	r;
	int		n;

	if (self->health < (self->max_health / 2))
			self->s.skinnum |= 1;

	if (level.time < self->pain_debounce_time)
	{
		if ((self->velocity[2] > 100) && ( (self->monsterinfo.active_move.pointer() == &soldierh_move_pain1) || (self->monsterinfo.active_move.pointer() == &soldierh_move_pain2) || (self->monsterinfo.active_move.pointer() == &soldierh_move_pain3)))
			M_SetAnimation(self, &soldierh_move_pain4);
		return;
	}

	self->pain_debounce_time = level.time + 3;

//	n = self->s.skinnum | 1;
	n = self->s.skinnum | 1;
	if (n == 1)
		gi.sound (self, CHAN_VOICE, h_sound_pain_ripper, 1, ATTN_NORM, 0);
	else if (n == 3)
		gi.sound (self, CHAN_VOICE, h_sound_pain_hypergun, 1, ATTN_NORM, 0);
	else
		gi.sound (self, CHAN_VOICE, h_sound_pain_lasergun, 1, ATTN_NORM, 0);

	if (self->velocity[2] > 100)
	{
		M_SetAnimation(self, &soldierh_move_pain4);
		return;
	}

	if (skill->value == 3)
		return;		// no pain anims in nightmare

	r = frandom();

	if (r < 0.33)
		M_SetAnimation(self, &soldierh_move_pain1);
	else if (r < 0.66)
		M_SetAnimation(self, &soldierh_move_pain2);
	else
		M_SetAnimation(self, &soldierh_move_pain3);
}


//
// ATTACK
//

extern void brain_dabeam (edict_t *self);

void soldierh_laserbeam (edict_t *self, int flash_index)
{

	vec3_t forward, right, up;
	vec3_t tempang, start;
	vec3_t	dir, angles, end;
	vec3_t	tempvec;
	edict_t *ent;

	// RAFAEL
	// this sound can't be called this frequent
//	if (frandom() > 0.8)
//		gi.sound (self, CHAN_AUTO, h_sound_lasergun_fire, 1, ATTN_STATIC, 0);

	VectorCopy (self->s.origin, start);
	VectorCopy (self->enemy->s.origin, end);
	VectorSubtract (end, start, dir);
	vectoangles (dir, angles);
	VectorCopy (monster_flash_offset[flash_index], tempvec);

	// Zaero add
	if (EMPNukeCheck(self, self->s.origin))
	{
		gi.sound (self, CHAN_AUTO, gi.soundindex("items/empnuke/emp_missfire.wav"), 1, ATTN_NORM, 0);
		return;
	}
	// end Zaero

	// RAFAEL
	// this sound can't be called this frequent
	if (frandom() > 0.8)
		gi.sound (self, CHAN_AUTO, h_sound_lasergun_fire, 1, ATTN_STATIC, 0);

	ent = G_Spawn ();
	VectorCopy (self->s.origin, ent->s.origin);
	VectorCopy (angles, tempang);
	AngleVectors (tempang, forward, right, up);
	VectorCopy (tempang, ent->s.angles);
	VectorCopy (ent->s.origin, start);

	if (flash_index == 85)
	{
		VectorMA (start, tempvec[0]-14, right, start);
		VectorMA (start, tempvec[2]+8, up, start);
		VectorMA (start, tempvec[1], forward, start);
	}
	else
	{
		VectorMA (start, tempvec[0]+2, right, start);
		VectorMA (start, tempvec[2]+8, up, start);
		VectorMA (start, tempvec[1], forward, start);
	}

	VectorCopy (start, ent->s.origin);
	ent->enemy = self->enemy;
	ent->owner = self;

	ent->dmg = 2;

	monster_fire_dabeam (ent);
}


void soldierh_fire (edict_t *self, int flash_number)
{
	vec3_t	start;
	vec3_t	forward, right, up;
	vec3_t	aim;
	vec3_t	dir;
	vec3_t	end;
	float	r, u;
	int		flash_index;
	bool tone = true;

//	if ((self->s.skinnum % 6) < 2)
	if (self->s.skinnum < 2)
#ifdef KMQUAKE2_ENGINE_MOD
		flash_index = ionripper_flash[flash_number]; // ripper
#else
		flash_index = blaster_flash[flash_number]; // ripper
#endif	// KMQUAKE2_ENGINE_MOD
//	else if ((self->s.skinnum % 6) < 4)
	else if (self->s.skinnum < 4)
#ifdef KMQUAKE2_ENGINE_MOD
		flash_index = hyperblaster_flash[flash_number]; // hyperblaster
#else
		flash_index = blaster_flash[flash_number]; // hyperblaster
#endif	// KMQUAKE2_ENGINE_MOD
	else // if (self->s.skinnum < 6)
		flash_index = machinegun_flash[flash_number]; // laserbeam

	AngleVectors (self->s.angles, forward, right, NULL);
	G_ProjectSource (self->s.origin, monster_flash_offset[flash_index], forward, right, start);

	if (flash_number == 5 || flash_number == 6)
	{
		VectorCopy (forward, aim);
	}
	else
	{
		VectorCopy (self->enemy->s.origin, end);
		end[2] += self->enemy->viewheight;

		// Lazarus fog reduction of accuracy
		if (self->monsterinfo.visibility < FOG_CANSEEGOOD)
		{
			end[0] += cfrandom() * 640 * (FOG_CANSEEGOOD - self->monsterinfo.visibility);
			end[1] += cfrandom() * 640 * (FOG_CANSEEGOOD - self->monsterinfo.visibility);
			end[2] += cfrandom() * 320 * (FOG_CANSEEGOOD - self->monsterinfo.visibility);
		}

		VectorSubtract (end, start, aim);
		vectoangles (aim, dir);
		AngleVectors (dir, forward, right, up);

		r = cfrandom()*100;
		u = cfrandom()*50;
		// Knightmare- adjust spread for expanded world size
#ifdef KMQUAKE2_ENGINE_MOD
		r *= (WORLD_SIZE / 8192);
		u *= (WORLD_SIZE / 8192);
#endif
		VectorMA (start, WORLD_SIZE, forward, end);	// was 8192
		VectorMA (end, r, right, end);
		VectorMA (end, u, up, end);

		VectorSubtract (end, start, aim);
		VectorNormalize (aim);
	}

//	if ((self->s.skinnum % 6) <= 1)
	if (self->s.skinnum <= 1)
	{
		// RAFAEL 24-APR-98
		// droped the damage from 15 to 5
		monster_fire_ionripper (self, start, aim, 8, 600, flash_index, EF_IONRIPPER);
	}
//	else if ((self->s.skinnum % 6) <= 3)
	else if (self->s.skinnum <= 3)
	{
	//	monster_fire_blueblaster (self, start, aim, 4, 600, MZ_BLUEHYPERBLASTER, EF_BLUEHYPERBLASTER);
	//	monster_fire_blueblaster (self, start, aim, 4, 600, flash_index, EF_BLUEHYPERBLASTER);	// Knightmare- use an actual monster muzzleflash here!
		monster_fire_blaster (self, start, aim, 4, 600, flash_index, EF_BLUEHYPERBLASTER, BLASTER_BLUE);
	}
	else // if (self->s.skinnum <= 5)
	{
		if (!(self->monsterinfo.aiflags & AI_HOLD_FRAME))
			self->monsterinfo.pausetime = level.time + (3 + rand() % 8) * FRAMETIME;

		soldierh_laserbeam (self, flash_index);

		if (level.time >= self->monsterinfo.pausetime)
			self->monsterinfo.aiflags &= ~AI_HOLD_FRAME;
		else
			self->monsterinfo.aiflags |= AI_HOLD_FRAME;
	}
}

// ATTACK1 (blaster/shotgun)

void soldierh_hyper_refire1 (edict_t *self)
{
//	if ((self->s.skinnum % 6) < 2)
	if (self->s.skinnum < 2)
		return;
//	else if ((self->s.skinnum % 6) < 4)
	else if (self->s.skinnum < 4)
	{
		if (frandom() < 0.7)
			self->s.frame = FRAME_attak103;
		else
			gi.sound (self, CHAN_AUTO, h_sound_hypergun_spindown, 1, ATTN_NORM, 0);	// Knightmare- use stored index
	}
}

void soldierh_ripper1 (edict_t *self)
{
//	if ((self->s.skinnum % 6) < 2)
	if (self->s.skinnum < 2)
		soldierh_fire (self, 0);
//	else if ((self->s.skinnum % 6) < 4)
	else if (self->s.skinnum < 4)
		soldierh_fire (self, 0);
}


void soldierh_fire1 (edict_t *self)
{
	soldierh_fire (self, 0);
}

void soldierh_attack1_refire1 (edict_t *self)
{
//	if ((self->s.skinnum % 6) > 1)
	if (self->s.skinnum > 1)
		return;

	if (self->enemy->health <= 0)
		return;

	if ( ((skill->value == 3) && (frandom() < 0.5)) || (range_to(self, self->enemy) == RANGE_MELEE) )
		self->monsterinfo.nextframe = FRAME_attak102;
	else
		self->monsterinfo.nextframe = FRAME_attak110;
}

void soldierh_attack1_refire2 (edict_t *self)
{
//	if ((self->s.skinnum % 6) < 2)
	if (self->s.skinnum < 2)
		return;

	if (self->enemy->health <= 0)
		return;

	if ( ((skill->value == 3) && (frandom() < 0.5)) || (range_to(self, self->enemy) == RANGE_MELEE) )
		self->monsterinfo.nextframe = FRAME_attak102;
}

void soldierh_hyper_sound (edict_t *self)
{
//	if ((self->s.skinnum % 6) < 2)
	if (self->s.skinnum < 2)
		return;
//	else if ((self->s.skinnum % 6) < 4)
	else if (self->s.skinnum < 4)
		gi.sound (self, CHAN_AUTO, h_sound_hypergun_loop, 1, ATTN_NORM, 0);	// Knightmare- use stored index
	else
		return;
}

mframe_t soldierh_frames_attack1 [] =
{
	{ai_charge, 0,  NULL},
	{ai_charge, 0,  soldierh_hyper_sound},
	{ai_charge, 0,  soldierh_fire1},
	{ai_charge, 0,  soldierh_ripper1},
	{ai_charge, 0,  soldierh_ripper1},
	{ai_charge, 0,  soldierh_attack1_refire1},
	{ai_charge, 0,  soldierh_hyper_refire1},
	{ai_charge, 0,  soldierh_cock},
	{ai_charge, 0,  soldierh_attack1_refire2},
	{ai_charge, 0,  NULL},
	{ai_charge, 0,  NULL},
	{ai_charge, 0,  NULL}
};
mmove_t soldierh_move_attack1 = {FRAME_attak101, FRAME_attak112, soldierh_frames_attack1, soldierh_run};

// ATTACK2 (blaster/shotgun)

void soldierh_hyper_refire2 (edict_t *self)
{
//	if ((self->s.skinnum % 6) < 2)
	if (self->s.skinnum < 2)
		return;
//	else if ((self->s.skinnum % 6) < 4)
	else if (self->s.skinnum < 4)
	{
		if (frandom() < 0.7)
			self->s.frame = FRAME_attak205;
		else
			gi.sound (self, CHAN_AUTO, h_sound_hypergun_spindown, 1, ATTN_NORM, 0);	// Knightmare- use stored index
	}
}

void soldierh_ripper2 (edict_t *self)
{
//	if ((self->s.skinnum % 6) < 2)
	if (self->s.skinnum < 2)
		soldierh_fire (self, 1);
//	else if ((self->s.skinnum % 6) < 4)
	else if (self->s.skinnum < 4)
		soldierh_fire (self, 1);
}

void soldierh_fire2 (edict_t *self)
{
	soldierh_fire (self, 1);
}


void soldierh_attack2_refire1 (edict_t *self)
{
//	if ((self->s.skinnum % 6) > 1)
	if (self->s.skinnum > 1)
		return;

	if (self->enemy->health <= 0)
		return;

	if ( ((skill->value == 3) && (frandom() < 0.5)) || (range_to(self, self->enemy) == RANGE_MELEE))
		self->monsterinfo.nextframe = FRAME_attak204;
	else
		self->monsterinfo.nextframe = FRAME_attak216;
}

void soldierh_attack2_refire2 (edict_t *self)
{
//	if ((self->s.skinnum % 6) < 2)
	if (self->s.skinnum < 2)
		return;

	if (self->enemy->health <= 0)
		return;

	if ( ((skill->value == 3) && (frandom() < 0.5))
	//	|| (range_to(self, self->enemy) == RANGE_MELEE) && (self->s.skinnum % 6) < 4)
		|| (range_to(self, self->enemy) == RANGE_MELEE) && (self->s.skinnum < 4) )
		self->monsterinfo.nextframe = FRAME_attak204;
}

mframe_t soldierh_frames_attack2 [] =
{
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, soldierh_hyper_sound},
	{ai_charge, 0, soldierh_fire2},
	{ai_charge, 0, soldierh_ripper2},
	{ai_charge, 0, soldierh_ripper2},
	{ai_charge, 0, soldierh_attack2_refire1},
	{ai_charge, 0, soldierh_hyper_refire2},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, soldierh_cock},
	{ai_charge, 0, NULL},
	{ai_charge, 0, soldierh_attack2_refire2},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL}
};
mmove_t soldierh_move_attack2 = {FRAME_attak201, FRAME_attak218, soldierh_frames_attack2, soldierh_run};

// ATTACK3 (duck and shoot)

void soldierh_duck_down (edict_t *self)
{
	if (self->monsterinfo.aiflags & AI_DUCKED)
		return;
	self->monsterinfo.aiflags |= AI_DUCKED;
	self->maxs[2] -= 32;
	self->takedamage = true;
	self->monsterinfo.pausetime = level.time + 1;
	gi.linkentity (self);
}

void soldierh_duck_up (edict_t *self)
{
	self->monsterinfo.aiflags &= ~AI_DUCKED;
	self->maxs[2] += 32;
	self->takedamage = true;
	gi.linkentity (self);
}

void soldierh_fire3 (edict_t *self)
{
	soldierh_duck_down (self);
	soldierh_fire (self, 2);
}

void soldierh_attack3_refire (edict_t *self)
{
	if ((level.time + 0.4) < self->monsterinfo.pausetime)
		self->monsterinfo.nextframe = FRAME_attak303;
}

mframe_t soldierh_frames_attack3 [] =
{
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, soldierh_fire3},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, soldierh_attack3_refire},
	{ai_charge, 0, soldierh_duck_up},
	{ai_charge, 0, NULL},
	ai_charge, 0, NULL
};
mmove_t soldierh_move_attack3 = {FRAME_attak301, FRAME_attak309, soldierh_frames_attack3, soldierh_run};

// ATTACK4 (machinegun)

void soldierh_fire4 (edict_t *self)
{
	soldierh_fire (self, 3);
//
//	if (self->enemy->health <= 0)
//		return;
//
//	if ( ((skill->value == 3) && (frandom() < 0.5)) || (range_to(self, self->enemy) == RANGE_MELEE) )
//		self->monsterinfo.nextframe = FRAME_attak402;
}

mframe_t soldierh_frames_attack4 [] =
{
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, soldierh_fire4},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	ai_charge, 0, NULL
};
mmove_t soldierh_move_attack4 = {FRAME_attak401, FRAME_attak406, soldierh_frames_attack4, soldierh_run};

#if 0
// ATTACK5 (prone)

void soldierh_fire5 (edict_t *self)
{
	soldierh_fire (self, 4);
}

void soldierh_attack5_refire (edict_t *self)
{
	if (self->enemy->health <= 0)
		return;

	if ( ((skill->value == 3) && (frandom() < 0.5)) || (range_to(self, self->enemy) == RANGE_MELEE) )
		self->monsterinfo.nextframe = FRAME_attak505;
}

mframe_t soldierh_frames_attack5 [] =
{
	{ai_charge, 8, NULL},
	{ai_charge, 8, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, soldierh_fire5},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	ai_charge, 0, soldierh_attack5_refire
};
//mmove_t soldierh_move_attack5 = {FRAME_attak501, FRAME_attak508, soldierh_frames_attack5, soldierh_run};
#endif

// ATTACK6 (run & shoot)

void soldierh_fire8 (edict_t *self)
{
	soldierh_fire (self, 7);
}

void soldierh_attack6_refire (edict_t *self)
{
	if (self->enemy->health <= 0)
		return;

	if (range_to(self, self->enemy) < RANGE_MID)
		return;

	if (skill->value == 3)
		self->monsterinfo.nextframe = FRAME_runs03;
}

mframe_t soldierh_frames_attack6 [] =
{
	{ai_charge, 10, NULL},
	{ai_charge,  4, NULL},
	{ai_charge, 12, NULL},
	{ai_charge, 11, soldierh_fire8},
	{ai_charge, 13, NULL},
	{ai_charge, 18, NULL},
	{ai_charge, 15, NULL},
	{ai_charge, 14, NULL},
	{ai_charge, 11, NULL},
	{ai_charge,  8, NULL},
	{ai_charge, 11, NULL},
	{ai_charge, 12, NULL},
	{ai_charge, 12, NULL},
	ai_charge, 17, soldierh_attack6_refire
};
mmove_t soldierh_move_attack6 = {FRAME_runs01, FRAME_runs14, soldierh_frames_attack6, soldierh_run};

void soldierh_attack (edict_t *self)
{
	float r, chance;

	monster_done_dodge (self);
	//Knightmare- no blindfire for ripper soldiers in old levels
	if (mp_monster_replace->value && (self->monsterinfo.aiflags & AI_BLOCKED))
		return;

	// PMM - blindfire!
	if (self->monsterinfo.attack_state == AS_BLIND)
	{
		// setup shot probabilities
		if (self->monsterinfo.blind_fire_delay < 1.0)
			chance = 1.0;
		else if (self->monsterinfo.blind_fire_delay < 7.5)
			chance = 0.4;
		else
			chance = 0.1;

		r = frandom();

		// minimum of 2 seconds, plus 0-3, after the shots are done
		self->monsterinfo.blind_fire_delay += 2.1 + 2.0 + frandom()*3.0;

		// don't shoot at the origin
		if (VectorCompare (self->monsterinfo.blind_fire_target, vec3_origin))
			return;

		// don't shoot if the dice say not to
		if (r > chance)
		{
//			if ((g_showlogic) && (g_showlogic->value))
//				gi.dprintf ("blindfire - NO SHOT\n");
			return;
		}

		// turn on manual steering to signal both manual steering and blindfire
		self->monsterinfo.aiflags |= AI_MANUAL_STEERING;
		M_SetAnimation(self, &soldierh_move_attack1);
		self->monsterinfo.attack_finished = level.time + 1.5 + frandom();
		return;
	}
	// pmm

// PMM - added this so the soldiers now run toward you and shoot instead of just stopping and shooting
//	if ((range_to(self, self->enemy) >= RANGE_MID) && (r < (skill->value*0.25) && ((self->s.skinnum % 6) <= 3)))

	r = frandom();

	if ((!(self->monsterinfo.aiflags & (AI_BLOCKED|AI_STAND_GROUND))) &&
		(range_to(self, self->enemy) >= RANGE_NEAR) &&
		(r < (skill->value*0.25) &&
	//	((self->s.skinnum % 6) <= 3)))
		(self->s.skinnum <= 3)))
	{
		M_SetAnimation(self, &soldierh_move_attack6);
	}
	else
	{
	//	if ((self->s.skinnum % 6) < 4)
		if (self->s.skinnum < 4)
		{
			if (frandom() < 0.5)
				M_SetAnimation(self, &soldierh_move_attack1);
			else
				M_SetAnimation(self, &soldierh_move_attack2);
		}
		else
		{
			M_SetAnimation(self, &soldierh_move_attack4);
		}
	}
}

//
// SIGHT
//

void soldierh_sight (edict_t *self, edict_t *other)
{
	if (frandom() < 0.5)
		gi.sound (self, CHAN_VOICE, h_sound_sight1, 1, ATTN_NORM, 0);
	else
		gi.sound (self, CHAN_VOICE, h_sound_sight2, 1, ATTN_NORM, 0);

	if ((skill->value > 0) && (range_to(self, self->enemy) >= RANGE_MID))
	{
		if (frandom() > 0.5)
		{
		//	if ((self->s.skinnum % 6) < 4)
			if (self->s.skinnum < 4)
				M_SetAnimation(self, &soldierh_move_attack6);
			else
				M_SetAnimation(self, &soldierh_move_attack4);
		}
	}
}

//
// DUCK
//

void soldierh_duck_hold (edict_t *self)
{
	if (level.time >= self->monsterinfo.pausetime)
		self->monsterinfo.aiflags &= ~AI_HOLD_FRAME;
	else
		self->monsterinfo.aiflags |= AI_HOLD_FRAME;
}

mframe_t soldierh_frames_duck [] =
{
	{ai_move, 5, soldierh_duck_down},
	{ai_move, -1, soldierh_duck_hold},
	{ai_move, 1, NULL},
	{ai_move, 0, soldierh_duck_up},
	{ai_move, 5, NULL}
};
mmove_t soldierh_move_duck = {FRAME_duck01, FRAME_duck05, soldierh_frames_duck, soldierh_run};

void soldierh_dodge (edict_t *self, edict_t *attacker, float eta)
{
	float	r;

	r = frandom();
	if (r > 0.25)
		return;

	if (!self->enemy)
		self->enemy = attacker;

	if (skill->value == 0)
	{
		M_SetAnimation(self, &soldierh_move_duck);
		return;
	}

	self->monsterinfo.pausetime = level.time + eta + 0.3;
	r = frandom();

	if (skill->value == 1)
	{
		if (r > 0.33)
			M_SetAnimation(self, &soldierh_move_duck);
		else
			M_SetAnimation(self, &soldierh_move_attack3);
		return;
	}

	if (skill->value >= 2)
	{
		if (r > 0.66)
			M_SetAnimation(self, &soldierh_move_duck);
		else
			M_SetAnimation(self, &soldierh_move_attack3);
		return;
	}

	M_SetAnimation(self, &soldierh_move_attack3);
}

//
// NEW DODGE CODE
//
// Knightmare- moved this code down here below soldierh frame declarations
void soldier_sidestep (edict_t *self)
{
//	if ((self->s.skinnum % 6) <= 3)
	if (self->s.skinnum <= 3)
	{
//		if ((g_showlogic) && (g_showlogic->value))
//			gi.dprintf ("shooting back!\n");
		if ((self->monsterinfo.active_move.pointer() != &soldier_move_attack6)
		|| (self->monsterinfo.active_move.pointer() != &soldierh_move_attack6))
		{	//Knightmare- make sure the Xatrix grunts fire the right weapon!!
			if ((!strcmp(self->classname, "monster_soldier_ripper"))
			|| (!strcmp(self->classname, "monster_soldier_hypergun"))
			|| (!strcmp(self->classname, "monster_soldier_lasergun")))
				M_SetAnimation(self, &soldierh_move_attack6);
			else
				M_SetAnimation(self, &soldier_move_attack6);
		}
	}
	else
	{
//		if ((g_showlogic) && (g_showlogic->value))
//			gi.dprintf ("strafing away!\n");
		if (self->monsterinfo.active_move.pointer() != &soldier_move_start_run)
			M_SetAnimation(self, &soldier_move_start_run);
	}
}

void soldier_duck (edict_t *self, float eta)
{
	float r;

	// has to be done immediately otherwise he can get stuck
	monster_duck_down(self);

	if (skill->value == 0)
	{
		// PMM - stupid dodge
		self->monsterinfo.nextframe = FRAME_duck01;
		M_SetAnimation(self, &soldier_move_duck);
		self->monsterinfo.duck_wait_time = level.time + eta + 1;
		return;
	}

	r = frandom();

	if (r > (skill->value * 0.3))
	{
		self->monsterinfo.nextframe = FRAME_duck01;
		M_SetAnimation(self, &soldier_move_duck);
		self->monsterinfo.duck_wait_time = level.time + eta + (0.1 * (3 - skill->value));
	}
	else
	{
		self->monsterinfo.nextframe = FRAME_attak301;
		if ((!strcmp(self->classname, "monster_soldier_ripper"))
		|| (!strcmp(self->classname, "monster_soldier_hypergun"))
		|| (!strcmp(self->classname, "monster_soldier_lasergun")))
			M_SetAnimation(self, &soldierh_move_attack3);
		else
			M_SetAnimation(self, &soldier_move_attack3);
		self->monsterinfo.duck_wait_time = level.time + eta + 1;
	}
	return;
}

//
// DEATH
//

void soldierh_fire6 (edict_t *self)
{

	// no fire laser
//	if ((self->s.skinnum % 6) < 4)
	if (self->s.skinnum < 4)
		soldierh_fire (self, 5);

}

void soldierh_fire7 (edict_t *self)
{

	// no fire laser
//	if ((self->s.skinnum % 6) < 4)
	if (self->s.skinnum < 4)
		soldierh_fire (self, 6);

}

void soldierh_dead (edict_t *self)
{
	VectorSet (self->mins, -16, -16, -24);
	VectorSet (self->maxs, 16, 16, -8);
	self->movetype = MOVETYPE_TOSS;
	self->svflags |= SVF_DEADMONSTER;
	self->nextthink = 0;
	gi.linkentity (self);
	M_FlyCheck (self);

	// Lazarus monster fade
	if (world->effects & FX_WORLDSPAWN_CORPSEFADE)
	{
		self->think=FadeDieSink;
		self->nextthink=level.time+corpse_fadetime->value;
	}
}

mframe_t soldierh_frames_death1 [] =
{
	{ai_move, 0,  NULL},
	{ai_move, -10, NULL},
	{ai_move, -10, NULL},
	{ai_move, -10, NULL},
	{ai_move, -5, NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  soldierh_fire6},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  soldierh_fire7},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL}
};
mmove_t soldierh_move_death1 = {FRAME_death101, FRAME_death136, soldierh_frames_death1, soldierh_dead};

mframe_t soldierh_frames_death2 [] =
{
	{ai_move, -5, NULL},
	{ai_move, -5, NULL},
	{ai_move, -5, NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL}
};
mmove_t soldierh_move_death2 = {FRAME_death201, FRAME_death235, soldierh_frames_death2, soldierh_dead};

mframe_t soldierh_frames_death3 [] =
{
	{ai_move, -5, NULL},
	{ai_move, -5, NULL},
	{ai_move, -5, NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
};
mmove_t soldierh_move_death3 = {FRAME_death301, FRAME_death345, soldierh_frames_death3, soldierh_dead};

mframe_t soldierh_frames_death4 [] =
{
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL}
};
mmove_t soldierh_move_death4 = {FRAME_death401, FRAME_death453, soldierh_frames_death4, soldierh_dead};

mframe_t soldierh_frames_death5 [] =
{
	{ai_move, -5, NULL},
	{ai_move, -5, NULL},
	{ai_move, -5, NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},

	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL}
};
mmove_t soldierh_move_death5 = {FRAME_death501, FRAME_death524, soldierh_frames_death5, soldierh_dead};

mframe_t soldierh_frames_death6 [] =
{
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL},
	{ai_move, 0,  NULL}
};
mmove_t soldierh_move_death6 = {FRAME_death601, FRAME_death610, soldierh_frames_death6, soldierh_dead};

void soldierh_die (edict_t *self, edict_t *inflictor, edict_t *attacker, int damage, vec3_t point)
{
	int		n;

	// check for gib
	if (self->health <= self->gib_health && !(self->spawnflags & SF_MONSTER_NOGIB))
	{
		gi.sound (self, CHAN_VOICE, gi.soundindex ("misc/udeath.wav"), 1, ATTN_NORM, 0);
		for (n = 0; n < 3; n++)
			ThrowGib (self, "models/objects/gibs/sm_meat/tris.md2", 0, 0, damage, GIB_ORGANIC);
		ThrowGib (self, "models/objects/gibs/chest/tris.md2", 0, 0, damage, GIB_ORGANIC);
		ThrowHead (self, "models/objects/gibs/head2/tris.md2", 0, 0, damage, GIB_ORGANIC);

		self->deadflag = DEAD_DEAD;
		return;
	}

	if (self->deadflag)
		return;

	// regular death
	self->s.skinnum |= 1;
	self->deadflag = DEAD_DEAD;
	self->takedamage = true;
	self->monsterinfo.power_armor_type = POWER_ARMOR_NONE;

//	if ((self->s.skinnum % 6) == 1)
	if (self->s.skinnum <= 1)
		gi.sound (self, CHAN_VOICE, h_sound_death_ripper, 1, ATTN_NORM, 0);
//	else if ((self->s.skinnum % 6) == 3)
	else if (self->s.skinnum <= 3)
		gi.sound (self, CHAN_VOICE, h_sound_death_hypergun, 1, ATTN_NORM, 0);
	else // ((self->s.skinnum % 6) == 5)
		gi.sound (self, CHAN_VOICE, h_sound_death_lasergun, 1, ATTN_NORM, 0);

	if (fabs((self->s.origin[2] + self->viewheight) - point[2]) <= 4)
	{
		// head shot
		M_SetAnimation(self, &soldierh_move_death3);
		return;
	}

	n = rand() % 5;
	if (n == 0)
		M_SetAnimation(self, &soldierh_move_death1);
	else if (n == 1)
		M_SetAnimation(self, &soldierh_move_death2);
	else if (n == 2)
		M_SetAnimation(self, &soldierh_move_death4);
	else if (n == 3)
		M_SetAnimation(self, &soldierh_move_death5);
	else
		M_SetAnimation(self, &soldierh_move_death6);
}

//
// SPAWN
//

void SP_monster_soldier_x (edict_t *self)
{
	self->s.modelindex = gi.modelindex ("models/monsters/soldier/tris.md2");
	//PMM
//	self->s.effects |= EF_SPLATTER;
	//PMM
	self->monsterinfo.scale = MODEL_SCALE;
	self->mins = {-16, -16, -24};
	self->maxs = {16, 16, 32};
	self->movetype = MOVETYPE_STEP;
	self->solid = SOLID_BBOX;

	sound_idle =	gi.soundindex ("soldier/solidle1.wav");
	sound_sight1 =	gi.soundindex ("soldier/solsght1.wav");
	sound_sight2 =	gi.soundindex ("soldier/solsrch1.wav");
	sound_cock =	gi.soundindex ("infantry/infatck3.wav");

	if (!self->mass)
		self->mass = 100;

	self->pain = soldier_pain;
	self->die = soldier_die;

	self->monsterinfo.stand = soldier_stand;
	self->monsterinfo.walk = soldier_walk;
	self->monsterinfo.run = soldier_run;
	self->monsterinfo.dodge = M_MonsterDodge;
	self->monsterinfo.attack = soldier_attack;
	self->monsterinfo.melee = NULL;
	self->monsterinfo.sight = soldier_sight;

//=====
//ROGUE
	self->monsterinfo.blocked = soldier_blocked;
	self->monsterinfo.duck = soldier_duck;
	self->monsterinfo.unduck = monster_duck_up;
	self->monsterinfo.sidestep = soldier_sidestep;
//ROGUE
//=====

	gi.linkentity (self);
	M_SetAnimation(self, &soldier_move_stand1);
	walkmonster_start (self);
}