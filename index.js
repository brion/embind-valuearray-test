Module = {
	onRuntimeInitialized: function() {
		console.log('val', Module.getPoint2fVal());
		console.log('ptr', Module.getPoint2fPtr());
		console.log('nullptr', Module.getPoint2fNull());
	}
};
