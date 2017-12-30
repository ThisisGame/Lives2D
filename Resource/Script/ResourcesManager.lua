local ResourcesManager=
{
	mDataPath,
}

function ResourcesManager:DataPath()
	if mDataPath==nil then
		mDataPath=Application:DataPath()
	end
	
	return mDataPath
end






return ResourcesManager