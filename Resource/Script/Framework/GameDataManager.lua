GameDataManager = {
    LocalTypeObject = {},
    LocalTypeEquip = {},
    LocalTypeLight = {},
    LocalTypeEquipStrengthsuit = {}, --人物经验表
    Local_Type_skill = {}, --技能
    --Local_Type_skill_table={},--技能分类
    Local_Type_petskill = {}, --宠物技能
    Local_type_foot = {},--足迹
    Local_type_xianqi = {}, --仙器
    wyft_type_object_Cache = {},
    LocalTypePictrue={},     --Icon图集
}


function GameDataManager:GetData(matchingKey, matchingValue, data)
    --a = os.clock()
    --for i = 1, #data do
    --    if data[i][matchingKey] == matchingValue then
    --        return data[i]
    --    end
    --end

    for k, v in ipairs(data) do
        if v[matchingKey] == matchingValue then
            return v
        end
    end

    --b = os.clock()
    --print(b-a)
end


function GameDataManager:getTypeObject(findValue, findName)
    local TypeObject = nil
    local tmpIndex = wyft_type_object_key[findName]

    for key, value in pairs(self.wyft_type_object_Cache) do
        if (value[tmpIndex] == findValue) then
            TypeObject = value
            break
        end
    end

    if (TypeObject == nil) then
        for key, value in pairs(wyft_type_object) do
            if value[tmpIndex] == findValue then
                TypeObject = value
                table.insert(self.wyft_type_object_Cache, TypeObject)
                --wyft_type_object_Cache.insert(TypeObject,findName)
                break
            end
        end
    end

    return TypeObject
end

function GameDataManager:wyft_type_object(objectID)
    local tempData
    --从缓存的数据中寻找
    tempData = self.LocalTypeObject[objectID]

    --如果没有缓存的话从表里寻找
    if tempData == nil then
        local key = wyft_type_object_key.id
        tempData = self:GetData(key, objectID, wyft_type_object)
        if tempData ~= nil then
            table.insert(self.LocalTypeObject, objectID, tempData)
        end
    end

    return tempData
end

function GameDataManager:wyft_type_equip(equipID)
    local tempData
    --从缓存的数据中寻找
    tempData = self.LocalTypeEquip[equipID]

    --如果没有缓存的话从表里寻找
    if tempData == nil then
        local key = wyft_type_equip_key.equipid
        tempData = self:GetData(key, equipID, wyft_type_equip)
        if tempData ~= nil then
            table.insert(self.LocalTypeEquip, equipID, tempData)
        end
    end

    return tempData
end

function GameDataManager:type_light(objectID)
    local tempData
    --从缓存的数据中寻找
    tempData = self.LocalTypeLight[objectID]

    --如果没有缓存的话从表里寻找
    if tempData == nil then
        local key = type_light_key.objectid
        tempData = self:GetData(key, objectID, type_light)
        table.insert(self.LocalTypeLight, objectID, tempData)
    end

    return tempData
end

--人物经验表
function GameDataManager:wyft_type_equip_strengthsuit_table(strength)
    local dataList = self.LocalTypeEquipStrengthsuit[strength]
    if dataList ~= nil then
        return dataList
    else
        dataList = {}
        self.LocalTypeEquipStrengthsuit[strength] = dataList
    end

    local data = wyft_type_equip_strengthsuit
    local dataKey = wyft_type_equip_strengthsuit_key.strength
    for k, v in ipairs(data) do
        if v[dataKey] == strength then
            table.insert(dataList, v)
        end
    end
    return dataList
end

--diamond_property
function GameDataManager:wyft_type_diamond_property(objectID)
    local matchingKey = wyft_type_diamond_property_key.object_id
    return self:GetData(matchingKey, objectID, data)
end

--diamond_suit
function GameDataManager:wyft_type_diamond_suit(totalLevel)
    local matchingKey = wyft_type_diamond_suit_key.dialevel
    local data = wyft_type_diamond_suit
    local tempData
    local currLeveltData, nextLevelData
    for i = 1, #data do
        tempData = data[i]
        if totalLevel >= tempData[matchingKey] then
            currLeveltData = tempData
            nextLevelData = data[i + 1]
        end
    end
    return currLeveltData, nextLevelData
end

--godforge_suit
function GameDataManager:wyft_type_godforge_suit()
    return wyft_type_godforge_suit
end

--type_skill
function GameDataManager:wyft_type_skill_by_profession(profession)
    local dataList = self.Local_Type_skill_table[profession]
    if dataList ~= nil then
        return dataList
    else
        dataList = {}
        self.Local_Type_skill_table[profession] = dataList
    end

    local data = wyft_type_skill
    local dataKey = wyft_type_skill_key.profession
    for k, v in ipairs(data) do
        if v[dataKey] == profession then
            table.insert(dataList, v)
        end
    end
    return dataList
end

--type_skill
function GameDataManager:wyft_type_skill_by_skillid(skillid)
    local tempData = self.Local_Type_skill[skillid]
    if tempData ~= nil then
        return tempData
    end

    tempData = self:GetData(wyft_type_skill_key.skillid, skillid, wyft_type_skill)
    if tempData ~= nil then
        self.Local_Type_skill[skillid] = tempData
    end
    return tempData
end

--type_ride
function GameDataManager:wyft_type_ride(gradelevel)
    return self:GetData(wyft_type_ride_key.gradelevel, gradelevel, wyft_type_ride)
end

--type_petskill
function GameDataManager:wyft_type_petskill_by_skillid(skillid)
    local tempData = self.Local_Type_petskill[skillid]
    if tempData ~= nil then
        return tempData
    end
    tempData = self:GetData(wyft_type_petskill_key.skillid, skillid, wyft_type_petskill)
    if tempData ~= nil then
        self.Local_Type_petskill[skillid] = tempData
    end
    return tempData
end

--type_petskill
function GameDataManager:wyft_type_petskill_get_parentskill(skillid)
    local tempData = self:wyft_type_petskill_by_skillid(skillid)
    if tempData ~= nil then
        tempData = self:wyft_type_petskill_by_skillid(tempData[wyft_type_petskill_key.skillid])
    end
    return tempData
end

--type_pet_bornskill
function GameDataManager:wyft_type_pet_bornskill_by_skillid(skillid)
    return self:GetData(wyft_type_pet_bornskill_key.skillid, skillid, wyft_type_pet_bornskill)
end

--type_footfashion_model
function GameDataManager:wyft_type_footfashion_model(rank)
    return self:GetData(wyft_type_footfashion_model_key.rank, rank, wyft_type_footfashion_model)
end

--type_foot
function GameDataManager:wyft_type_foot_by_level(level)
    local tempData = self.Local_type_foot[level]
    if tempData ~= nil then
        return tempData
    end
    tempData = self:GetData(wyft_type_foot_key.level, level, wyft_type_foot)
    if tempData ~= nil then
        self.Local_type_foot[level] = tempData
    end
    return tempData
end

--type_wingsfashion_model
function GameDataManager:wyft_type_wingsfashion_model(rank)
    return self:GetData(wyft_type_wingsfashion_model_key.rank, rank, wyft_type_wingsfashion_model)
end

--type_wings
function GameDataManager:wyft_type_wings(wings_id)
    return self:GetData(wyft_type_wings_key.wings_id, wings_id, wyft_type_wings)
end

--type_trump
function GameDataManager:wyft_type_trump_by_trumptype(trumptype)
    return self:GetData(wyft_type_trump_key.trumptype, trumptype, wyft_type_trump)
end

--type_xianqi
function GameDataManager:wyft_type_xianqi(nowlv)
    local tempData = self.Local_type_xianqi[nowlv]
    if tempData ~= nil then
        return tempData
    end
    tempData = self:GetData(wyft_type_xianqi_key.nowlv, nowlv, wyft_type_xianqi)
    if tempData ~= nil then
        self.Local_type_xianqi[nowlv] = tempData
    end
    return tempData
end

--type_artifact_name
function GameDataManager:wyft_type_artifact_name(item_type)
    return self:GetData(wyft_type_artifact_name_key.item_type, item_type, wyft_type_artifact_name)
end

--type_model_ui_godweapon
function GameDataManager:wyft_type_model_ui_godweapon(kind)
    return self:GetData(wyft_type_model_ui_godweapon_key.kind, kind, wyft_type_model_ui_godweapon)
end

--type_godweapon_skill
function GameDataManager:wyft_type_godweapon_skill_get_list(kind)
    local type_godweapon_skill_table = {} --神兵技能分类
    local data = wyft_type_godweapon_skill

    local matchingKey = wyft_type_godweapon_skill_key.kind

    for k, v in ipairs(data) do
        if v[matchingKey] == kind then
            table.insert(type_godweapon_skill_table, v)
        end
    end
    return type_godweapon_skill_table
end

--type_field
function GameDataManager:wyft_type_field(fieldid)
    return self:GetData(wyft_type_field_key.fieldid, fieldid, wyft_type_field)
end

--type_mustdone_property
function GameDataManager:wyft_type_mustdone_property_by_level(level)
    return self:GetData(wyft_type_mustdone_property_key.level, level, wyft_type_mustdone_property)
end

--type_rune_box
function GameDataManager:wyft_type_rune_box_get_list(boxid)
   local tempData = self:GetData(wyft_type_rune_box_key.boxid, boxid, wyft_type_rune_box)
    local lineList = {}
    if tempData[wyft_type_rune_box_key.line_1] >= 0 then
        table.insert(lineList, tempData[wyft_type_rune_box_key.line_1] )
    end
    if tempData[wyft_type_rune_box_key.line_2] >= 0 then
        table.insert(lineList, tempData[wyft_type_rune_box_key.line_2] )
    end
    if tempData[wyft_type_rune_box_key.line_3] >= 0 then
        table.insert(lineList, tempData[wyft_type_rune_box_key.line_3] )
    end
    return lineList
end

--type_ridefashion_model
function GameDataManager:wyft_type_ridefashion_model_by_rank(rank)
    return self:GetData(wyft_type_ridefashion_model_key.rank, rank, wyft_type_ridefashion_model)
end

--幻化时装表
function GameDataManager:wyft_type_fashion(objectID)
    local tempData
    --从缓存的数据中寻找
    tempData = self.LocalTypeFashion[objectID]

    --如果没有缓存的话从表里寻找
    if tempData == nil then
        local key = wyft_type_fashion_key.fashion_id
        tempData = self:GetData(key, objectID, wyft_type_fashion)
        if tempData ~= nil then
            table.insert(self.LocalTypeFashion, objectID, tempData)
        end
    end

    return tempData
end


--Icon图集表
function GameDataManager:type_picture(objectID)
    local tempData
    --从缓存的数据中寻找
    tempData = self.LocalTypePictrue[objectID]

    --如果没有缓存的话从表里寻找
    if tempData == nil then
        local key = type_picture_key.icon
        tempData = self:GetData(key, objectID, type_picture)
        if tempData ~= nil then
            table.insert(self.LocalTypePictrue, objectID, tempData)
        end
    end

    return tempData
end



return GameDataManager