$modules = (Get-Content 'src/registry/modules.json' -Raw | ConvertFrom-Json).modules
Write-Host "Total modules: $($modules.Count)"
$last = $modules[-1]
Write-Host "Last ID: $($last.id) | $($last.name) | $($last.category)"
Write-Host "Last 3:"
$modules[-3..-1] | ForEach-Object { Write-Host "  $($_.id): $($_.name) [$($_.category)] $($_.bus)" }

$boards = (Get-Content 'src/registry/boards.json' -Raw | ConvertFrom-Json).boards
Write-Host "Total boards: $($boards.Count)"
Write-Host "Last board: $($boards[-1].id) | $($boards[-1].name) | $($boards[-1].family)"
Write-Host "First board keys: $($boards[0].PSObject.Properties.Name -join ', ')"