when xxstage.server_timer begin
    if d.select(get_server_timer_arg()) then
        d.clear_regen()
        d.kill_all()
        d.setf("level", xx)
        d.set_dungeon_state(1) -- 1: metinstone, 2: midboss, 3: mainboss -> enum EDungeonStages
        local bossVid = d.spawn_mob(metinstonevnum, x, y)
        d.set_unique("bossvid", bossVid)
        d.zodiac_notice_clear()
        d.zodiac_notice("Hit the metinstone up to 50% health to start the inner phase")
        clear_server_timer("xxstage", d.get_map_index())
        server_loop_timer("controlhp", 5, d.get_map_index())
    end
end

when controlhp.server_timer begin
    if d.select(get_server_timer_arg()) then
        if d.unique_get_hp_perc("bossvid") < 52 then -- dungeon_state is 1, so player can't hit metinstone under %50 hp
            d.zodiac_notice_clear()
            d.zodiac_notice("Inner phase started, kill all monsters")
            server_timer("xxstage2", 1, d.get_map_index()) -- start innerstage
            clear_server_timer("controlhp", d.get_map_index())
        end
    end
end

when xxstage2.server_timer begin
    if d.select(get_server_timer_arg()) then
        d.regen_file("example_dungeon/x.txt")
        server_loop_timer("controlmonstercount", 5, d.get_map_index())
        clear_server_timer("xxstage2", d.get_map_index())
    end
end

when controlmonstercount.server_timer begin
    if d.select(get_server_timer_arg()) then
        if d.count_monster() < 2 then
            d.zodiac_notice_clear()
            d.zodiac_notice("You've cleared the inner phase, kill the metinstone")
            d.clear_regen()
            d.set_dungeon_state(0) -- able to hit metinstone
            clear_server_timer("controlmonstercount", d.get_map_index())
        end
    end
end

when kill with npc.get_race() == metinstone_vnum and d.getf("level") == xx begin
    d.clear_regen()
    d.kill_all()
    server_timer("zzzstage", 1, d.get_map_index())
end