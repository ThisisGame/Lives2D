local DateTimeHelper={}

function DateTimeHelper:Now()
	return os.time()
end

function DateTimeHelper:Year()
	return os.date("*t",time).year
end

function DateTimeHelper:Month()
	return os.date("*t",time).month
end

function DateTimeHelper:Day()
	return os.date("*t",time).day
end

function DateTimeHelper:Hour()
	return os.date("*t",time).hour
end

function DateTimeHelper:Minite()
	return os.date("*t",time).min
end

function DateTimeHelper:Second()
	return os.date("*t",time).sec
end

return DateTimeHelper